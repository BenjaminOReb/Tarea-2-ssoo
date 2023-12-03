#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

// Función para cargar la imagen y representarla como una matriz de píxeles
Mat cargarImagen(const string& nombreImagen) {
    Mat imagen = imread(nombreImagen, IMREAD_COLOR);

// Se asegura de la cantidad de argumentos introducidos y en caso de error entrega una de que argumentos proporcionar
    if (imagen.empty()) {
        cerr << "No se pudo cargar la imagen: " << nombreImagen << endl;
        exit(1);
    }

    return imagen;
}

// Función para convertir la imagen a escala de grises de forma secuencial
void convertirAGrisesSecuencial(Mat& imagenColor, Mat& imagenGris) {
    for (int i = 0; i < imagenColor.rows; ++i) {
        for (int j = 0; j < imagenColor.cols; ++j) {
            Vec3b pixel = imagenColor.at<Vec3b>(i, j);
            uchar gris = pixel[0] * 0.07 + pixel[1] * 0.72 + pixel[2] * 0.21; //Formula de conversión a escala de grises
            imagenGris.at<uchar>(i, j) = gris;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <imagen_color> <imagen_gris>" << endl;
        return 1;
    }

    string nombreImagenColor = argv[1];
    string nombreImagenGris = argv[2];

    Mat imagenColor = cargarImagen(nombreImagenColor);
    Mat imagenGris(imagenColor.rows, imagenColor.cols, CV_8UC1);

    cout << "Cargando imgen..." << endl;
    cout << "Filas (altura): " << imagenColor.rows << " Columnas (ancho): " << imagenColor.cols << endl;

    auto start = chrono::high_resolution_clock::now(); // Inicio del conteo de tiempo

    // Conversión a escala de grises de manera secuencial
    convertirAGrisesSecuencial(imagenColor, imagenGris);

    auto end = chrono::high_resolution_clock::now(); // Fin del conteo de tiempo
    chrono::duration<double> tiempo_secuencial = end - start;

    cout << "Inicio de la conversion secuancial..." << endl;
    cout << "Fin de la conversion secuancial..." << endl;
    cout << "El tiempo total invertido en segundos secuencialmente es " << tiempo_secuencial.count() << " segundos" << endl;

    imwrite(nombreImagenGris, imagenGris);

    return 0;
}