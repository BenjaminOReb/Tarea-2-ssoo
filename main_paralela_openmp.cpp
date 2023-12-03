#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <omp.h>

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

// Función para convertir la imagen a escala de grises utilizando OpenMP
void convertirAGrisesOpenMP(Mat& imagenColor, Mat& imagenGris, int numHebras) {
    #pragma omp parallel num_threads(numHebras)
    {
        int hilo_id = omp_get_thread_num();
        int chunk_size = imagenColor.rows / numHebras;
        int inicio = hilo_id * chunk_size;
        int fin = (hilo_id == numHebras - 1) ? imagenColor.rows : (hilo_id + 1) * chunk_size;

        for (int i = inicio; i < fin; ++i) {
            for (int j = 0; j < imagenColor.cols; ++j) {
                Vec3b pixel = imagenColor.at<Vec3b>(i, j);
                uchar gris = pixel[0] * 0.07 + pixel[1] * 0.72 + pixel[2] * 0.21;
                imagenGris.at<uchar>(i, j) = gris;
            }
        }
    }
}

int main(int argc, char* argv[]) {
// Se asegura de la cantidad de argumentos introducidos y en caso de error entrega una de que argumentos proporcionar
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <imagen_color> <imagen_gris> <numero_hebras>" << endl;
        return 1;
    }

    string nombreImagenColor = argv[1];
    string nombreImagenGris = argv[2];
    int numHebras = atoi(argv[3]);

    Mat imagenColor = cargarImagen(nombreImagenColor);
    Mat imagenGris(imagenColor.rows, imagenColor.cols, CV_8UC1);

    cout << "Cargando imagen..." << endl;
    cout << "Filas (altura): " << imagenColor.rows << " Columnas (ancho): " << imagenColor.cols << endl;

    auto start = chrono::high_resolution_clock::now(); // Inicio del conteo de tiempo

    // Conversión a escala de grises utilizando OpenMP
    convertirAGrisesOpenMP(imagenColor, imagenGris, numHebras);

    auto end = chrono::high_resolution_clock::now(); // Fin del conteo de tiempo
    chrono::duration<double> tiempo_openmp = end - start;

    cout << "Inicio de la conversion con OpenMP..." << endl;
    cout << "Fin de la conversion con OpenMP..." << endl;
    cout << "El tiempo total invertido en segundos con OpenMP es " << tiempo_openmp.count() << " segundos" << endl;

    imwrite(nombreImagenGris, imagenGris);

    return 0;
}
