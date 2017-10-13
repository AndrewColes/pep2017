#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <utility>
using std::pair;

void printElements(const vector<int> & s) {
    for (auto & element : s) {
        cout << element << "\n";
    }
} 

int main() {
    vector<int> numbers{1,2,3,4,5};
    
    vector<int>::iterator itr = numbers.begin();    
    cout << *itr << "\n";
}
