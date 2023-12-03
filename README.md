# Tarea-2-ssoo
CONVERSIÓN DE IMÁGENES A ESCALA DE GRISES - SECUENCIAL, THREADS Y OPENMP EN C++	

Autores: Benjamín Ortega, Bruno Castillo.

Este proyecto tiene como objetivo realizar la conversión de una imagen a escala de grises utilizando diferentes enfoques: secuencial, paralelo con OpenMP y paralelo con threads en C++.

Se implementan tres versiones del programa:

    -Secuencial: Convierte la imagen a escala de grises de manera secuencial.
    -Paralela (Threads): Utiliza la clase std::thread para realizar la conversión en paralelo.
    -Paralela (OpenMP): Emplea la API OpenMP para la paralelización del proceso.

REQUISITOS:

    -Compilador GNU g++
    -Lirería OpenCV instalada
    -Sistema operativo Linux
  
INSTRUCCIONES DE USO

COMPILACIÓN
	Para compilar los programas, se deben ejecutar los siguientes comandos en la terminal:
	
	para el programa secuencial:
		make secuencial 
	
	Para el programa paralelo con threads:
		make paralela_threads
	
	Para el programa paralelo con OpenMP
		make paralela_openmp
		
EJECUCIÓN
	Una vez compilada cada versión, para ejecutar el programa, se utiiza el siguiente formato en terminal:
	
	para el programa secuencial:
		./programa_secuencial <imagen_color> <imagen_gris>
	
	Para el programa paralelo con threads:
		./programa_paralelo_threads <imagen_color> <imagen_gris> <numero_hebras>
	
	Para el programa paralelo con OpenMP
		./programa_paralelo_openmp <imagen_color> <imagen_gris> <numero_hebras>
	
	Donde <imagen_color> es el nombre de la imagen que se cambiará a escala de grises (en este caso la imagen incluida en el proyecto se llama auroras.jpg), <imagen_gris> es el nombre con el que se quiere guardar la imagen ya procesada y en el caso de las versiones paralelas, es necesario añadir <numero_hebras> para especificar la cantidad de hilos a utilizar.
	
EJEMPLO DE EJECUCION

	para el programa secuencial:
		./programa_secuencial auroras.jpg auroras_grises.jpg
	
	Para el programa paralelo con threads:
		./programa_paralelo_threads auroras.jpg auroras_grises_threads 4
	
	Para el programa paralelo con OpenMP
		./programa_paralelo_openmp auroras.jpg auroras_grises_opnmp 2		

RSULTADOS Y CONCLUSIONES

Para la version secuencial de un total de 5 pruebas se promedio un tiempo de ejecucion de 1.4639 segundos

Para la version paralela usando threads en un total de 5 intentos con 2 hilos se promedio un tiempo de 0.739239 segundos. En un total de 5 intentos con 10 hilos se promedio un tiempo de 0.671771 segundos

Para la vesion paralela usando la API de OpenMP en un total de 5 intentos con 2 hilos se promedio un tiempo de 0.737333 segundos. En un total de 5 intentos con 10 hilos se promedio un tiempo de 0.6361

Para concluir de los reultados obtenidos sabemos que la version más lenta es la secuencial con un tiempo de conversión de mas del doble que las versiones paralelas, el uso de mas hilos reduce el tiempo de conversión y la version de OpenMP es superior a la version con threads. De lo anterior decir que es de suma importancia la correcta implementacion de la API de OpenMP ya que en el caso contrario estuvo arrojando tiempos de conversion superiores a los 3 segundos, una vez corregido sus tiempos eran menores a los de la version con threads. En mi caso use una imagen de 11.4MB, deberia haber usado una de mucho mayor tamaño ya que las diferencias en los tiempos son mínimas pero de todos modos perceptibles.

ENLACE AL REPOSITORIO DE GIT
https://github.com/BenjaminOReb/Tarea-2-ssoo