#include <iostream>
#include <iterator>
#include <chrono>
#include "DataGroup.h"
#include <vector>
#include "Ordenamiento.h"

using namespace std;

vector <int> valores;

// Búsqueda secuencial
// Búsqueda secuencial con movimiento al frente
// Búsqueda secuencial con transposición
// Búsqueda secuencial con ordenamiento
// Búsqueda binaria
void tryAll(vector <int> desordenados, int buscado){
    Ordenamiento <int> sorter (desordenados);
    

    cout << "Empieza tiempo de: Búsqueda secuencial" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    sorter.sequentialSearch(buscado);
    auto finish = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda secuencial con movimiento al frente" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.sequentialFrontSearch(buscado);
    finish = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda secuencial con transposición" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.sequentialTranspositionSearch(buscado);
    finish = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda secuencial con ordenamiento" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.sequentialSortingSearch(buscado);
    finish = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda binaria" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.binarySearch(buscado);
    finish = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";
}

int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    int input;
    int lostNumbers [] = { 5, 19, 38, 69, 89};

    DataGroup <int> datos (100000);

    for (int x : lostNumbers){
        for (int i = 0; i<10 ; i++){
            cout << "----------------------Numero: " << x << ", "<< i<< endl;
            tryAll(datos.data, x);
        }
    }

    
    



    return 0;
}
