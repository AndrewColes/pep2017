#include "int_array.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

void printElementZero(const int_array & a) {
    cout << "Printing out element 0 from an array of size " << a.size() << endl;
    cout << a[0] << endl;
}

int main() {
    int_array numbers(3);
    numbers[0] = 42;
    numbers[1] = 43;
    numbers[2] = 44;
    
    {
        auto itr = numbers.begin();
        auto itrEnd = numbers.end();
        
        for (; itr != itrEnd; ++itr) {
            int & element = *itr;
            cout << *itr << "\n";
        }
    }
    
    for (int & element : numbers) {
        cout << element << "\n";
    }
    
    list<int> listOfNumbers{1,2,3,4,5,6};
    
    auto itr = listOfNumbers.begin();
    
    while (itr != listOfNumbers.end()) {
        if ((*itr % 2) == 0) {
            // even number
            ++itr;
        } else {
            // odd number
            itr = listOfNumbers.erase(itr);
        }
    }
    
    for (int & element : listOfNumbers) {
        cout << element << "\n";
    }
    
}
