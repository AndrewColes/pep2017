#include <iostream>
using std::cout;
using std::endl;

int answer() {
    return 42;
}

int b();
int a();

int a() {
    return b() + 7;
}

int b() {
    return 3 + a();
}

int small(int x) {
    return 2 * x  + 7;
}

void printAnswer(int x) {
    cout << "The answer to life the universe and "
         << "everything is " << x << endl;
}

int main() {
    printAnswer(answer());
    int something = 2 * 3  + 7;
    
    return 0;
}

