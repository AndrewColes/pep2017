#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void bigNumber() {
    cout << "Wow, it's really big!\n";
}

int main() {

    vector<int> numbers{1,2,3,4,5};

    for (int i = 0; i <= 50; ++i) {
        if (numbers[i] > 5) {
            bigNumber();
        }
    }

    cout << "Oh dear\n";
}
