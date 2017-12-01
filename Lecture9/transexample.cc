#include <vector>
using std::vector;

#include "transformreduce.h"

#include <iostream>
using std::cout;

int main() {

    vector<int> numbers(1000);
    for (int i = 0; i < 1000; ++i) { numbers[i] = i; }

    int soVeryBig = 
    transform_reduce(numbers.begin(), numbers.end(),
                     0,
                     [](const int soFar, const int nextAns) {
                         return soFar + nextAns;
                     },
                     [](const int element) {
                          int i = 0;
                          for (int waste = 0; waste < 1000; ++waste) {
                            for (int j = 1; j <= element; ++j) {
                                i += j;
                            }
                            for (int j = 1; j <= element; ++j) {
                                i -= j;
                            }
                          }
                          return i;
                    });
    
    cout << soVeryBig << "\n";
}
