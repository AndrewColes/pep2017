#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;


int main() {
    vector<int> numbers{1,14,-2,-4,9,-1,9001};
    vector<int> neg;

    std::copy_if(numbers.begin(),
                 numbers.end(),
                 std::back_inserter(neg),
                 [](const int x) {
                     return (x < 0);
                 });
    
    cout << neg.size() << " negative numbers\n";

}
