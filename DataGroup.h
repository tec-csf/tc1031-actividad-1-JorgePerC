#include <ctime> 
#include <vector>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

template <typename item>

// A class to store all data in a vector, 
// with multiple methods to fill the vector.
class DataGroup {
public:
    DataGroup (int);
    vector <item> data; //Attribute
    vector <item> createVector(int); // Method to fill a vector
    item random(); // Mehtod to have multiple values
};

template <typename item>
DataGroup <item>:: DataGroup(int size){
    this -> data = createVector(size);
}

template <typename item>
vector <item> DataGroup <item> :: createVector(int size){
    vector <item> unOrdered;
    unOrdered.reserve(size);
    cout << "Creating Vector" << endl;
    for (int i = 0; i < size; i++){
        unOrdered.push_back(random());
        // usleep(10000);
        // We sleep to get different numbers
        //this_thread::sleep_for(chrono::milliseconds(1000) );
    }
    cout << "Vector Created" << endl;
    return unOrdered;

}
// Generator for int
template <>
int DataGroup <int> :: random (){
    return rand() % 100 + 1;
}
// Generator for decimals
template <typename item>
item DataGroup <item> :: random (){
    return rand();
}

// template <>
// char DataGroup <char> :: random (){
//     srand(time(nullptr)); 
//     int numero = rand() % 100 + 1;
// }


