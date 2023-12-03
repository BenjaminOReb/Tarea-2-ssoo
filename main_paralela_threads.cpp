#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;

// Función para cargar la imagen y representarla como una matriz de píxeles
Mat cargarImagen(const string& nombreImagen) {
    Mat imagen = imread(nombreImagen, IMREAD_COLOR);

    if (imagen.empty()) {
        cerr << "No se pudo cargar la imagen: " << nombreImagen << endl;
        exit(1);
    }

    return imagen;
}

// Función para convertir la imagen a escala de grises utilizando threads
void convertirAGrisesThread(Mat& imagenColor, Mat& imagenGris, int inicio, int fin) {
    for (int i = inicio; i < fin; ++i) {
        for (int j = 0; j < imagenColor.cols; ++j) {
            Vec3b pixel = imagenColor.at<Vec3b>(i, j);
            uchar gris = pixel[0] * 0.07 + pixel[1] * 0.72 + pixel[2] * 0.21;
            imagenGris.at<uchar>(i, j) = gris;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <imagen_color> <imagen_gris> <numero_hebras>" << endl;
        return 1;
    }

    string nombreImagenColor = argv[1];
    string nombreImagenGris = argv[2];
    int numHebras = atoi(argv[3]);

    Mat imagenColor = cargarImagen(nombreImagenColor);
    Mat imagenGris(imagenColor.rows, imagenColor.cols, CV_8UC1);

    cout << "Cargando imgen..." << endl;
    cout << "Filas (altura): " << imagenColor.rows << " Columnas (ancho): " << imagenColor.cols << endl;

    auto start = chrono::high_resolution_clock::now(); // Inicio del conteo de tiempo

    // Conversión a escala de grises utilizando threads
    vector<thread> threads;
    int chunk = imagenColor.rows / numHebras;
    int inicio = 0;

    for (int i = 0; i < numHebras; ++i) {
        int fin = (i == numHebras - 1) ? imagenColor.rows : inicio + chunk;
        threads.emplace_back(convertirAGrisesThread, ref(imagenColor), ref(imagenGris), inicio, fin);
        inicio = fin;
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = chrono::high_resolution_clock::now(); // Fin del conteo de tiempo
    chrono::duration<double> tiempo_threads = end - start;

    cout << "Inicio de la conversion con threads..." << endl;
    cout << "Fin de la conversion con threads..." << endl;
    cout << "El tiempo total invertido en segundos con threads es " << tiempo_threads.count() << " segundos" << endl;

    imwrite(nombreImagenGris, imagenGris);

    return 0;
}
