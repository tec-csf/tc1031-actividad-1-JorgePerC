// #include "DataGroup.h"
#include <vector>

using namespace std;

template <class kind>
class Ordenamiento {
public:

    Ordenamiento(vector <kind> );
    // Private
    vector <kind> elements;
    int sequentialSearch(kind);
    int sequentialFrontSearch(kind);
    int sequentialTranspositionSearch(kind);
    int sequentialSortingSearch(kind);
    int binarySearch(kind);
};

template <class kind>
Ordenamiento <kind> :: Ordenamiento (vector <kind> elements){
    this -> elements = elements;
}

template <class kind>
int Ordenamiento <kind> ::sequentialSearch(kind lostElement){
    for (int i = 0 ; i < elements.size() ; i++){
        if (elements[i] == lostElement){
            return i;
        }
    } 
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::sequentialFrontSearch(kind lostElement){
    for (int i = 0 ; i < elements.size() ; i++){
        if (elements[i] == lostElement){
            swap(elements[i], elements[0]);
            return i;
        }
    } 
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::sequentialTranspositionSearch(kind lostElement){
    for (int i = 0 ; i < elements.size() ; i++){
        if (elements[i] == lostElement){
            if (i == 0){
                return i;
            }
            swap(elements[i], elements[i-1]);
            return i;
        }
    } 
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::sequentialSortingSearch(kind lostElement){
    for (int i = 0 ; i < elements.size()-1 ; i++)
        for (int j = i+1 ; j < elements.size() ; j++) {
            if (elements[i] > elements[j]){ 
                swap(elements[i], elements[j]);
            } 
            if (elements[i] == lostElement){
                return i;
            }
        }
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::binarySearch(kind lostElement){
    int central, low, high, centralValue;
    low = 0;
    high = elements.size()-1;
    while (low <= high) {
        central = (low + high)/2;
        centralValue = elements[central];
        if (lostElement == centralValue)
            return central;
        else if (lostElement < centralValue)
            high = central -1;
        else
            low = central + 1;
    }
    return -1;
}