CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pthread `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

.PHONY: all clean

all: secuencial paralela_threads paralela_openmp

secuencial: main_secuencial.cpp
	$(CXX) $(CXXFLAGS) $< -o programa_secuencial $(LDFLAGS)

paralela_threads: main_paralela_threads.cpp
	$(CXX) $(CXXFLAGS) $< -o programa_paralelo_threads $(LDFLAGS)

paralela_openmp: main_paralela_openmp.cpp
	$(CXX) $(CXXFLAGS) -fopenmp $< -o programa_paralelo_openmp $(LDFLAGS)

clean:
	rm -f programa_secuencial programa_paralelo_threads programa_paralelo_openmp