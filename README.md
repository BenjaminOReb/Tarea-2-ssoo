# Tarea-2-ssoo
CONVERSIÓN DE IMÁGENES A ESCALA DE GRISES - SECUANCIAL, THREADS Y OPENMP EN C++	

Autores: Benjamín Ortega, Bruno Castillo.

Este proyecto tiene como objetivo realizar la conversión de una imagen a escala de grises utilizando diferentes enfoques: secuencial, paralelo con OpenMP y paralelo con threads en C++.

Se implementan tres versiones del programa:

    -Secuencial: Convierte la imagen a escala de grises de manera secuencial.
    -Paralela (Threads): Utiliza la clase std::thread para realizar la conversión en paralelo.
    -Paralela (OpenMP): Emplea la API OpenMP para la paralelización del proceso.

REQUISITOS
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
	
	Donde <imagen_color> es el nombre de la imagen que se cambiará a escala de grises (En este caso la imagen incluida en el proyecto se llama auroras.jpg), <imagen_gris> es el nombre con el que se quiere guardar la imagen ya procesada (recomiendo guradarla con nombres diferentes para cada versión y recordar y es importante que lleve la extensión .jpg luego del nombre) y en el caso de las versiones paralelas, añade <numero_hebras> para especificar la cantidad de hilos a utilizar.
	
EJEMPLO DE EJECUCION

	para el programa secuencial:
		./programa_secuencial auroras.jpg auroras_grises.jpg
	
	Para el programa paralelo con threads:
		./programa_paralelo_threads auroras.jpg auroras_grises_threads 4
	
	Para el programa paralelo con OpenMP
		./programa_paralelo_openmp auroras.jpg auroras_grises_opnmp 2		
