#include <iostream>
using std::cout;

int main() {

    int lessThanThis = 0;

    auto fn = [&lessThanThis]() {
        lessThanThis += 7;
    };

    fn();

    cout << lessThanThis << "\n";
}
