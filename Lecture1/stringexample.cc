#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
    string a = "and";
    string b = "rew";
    
    string c = a + b;
    
    c[5] = 'i';
    cout << c << endl;
    
    return 0;
}
