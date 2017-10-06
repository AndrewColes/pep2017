#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    /*string * a = new string("Dave");
    string * b = new string("Dave");
    
    if (a == b) {
        cout << "Wait wut?\n";
    }
    
    cout << a << endl;
    cout << b << endl;*/
    
    int * a = new int[10];
    
    
    cout << "A is at " << a << endl;
    
    a[0] = 42;
    a[1] = 17;
    
    cout << a[0] << endl;
    cout << a[1] << endl;
    
    cout << *a << endl;
    
    int * secondElement = &(a[1]);
    
    cout << "A[0] is at " << a << endl;
    cout << "A[1] is at " << secondElement << endl;

    cout << "The size of an string is " << sizeof(string) << endl;
    
}
