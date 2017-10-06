#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class IHazStringPtr {

private:
    string * s;

public:

    IHazStringPtr()
    : s(new string()) {

    }

    IHazStringPtr(const IHazStringPtr & other) {
        s = new string(*(other.s));
    }
    
    ~IHazStringPtr() {
        cout << "About to delete a string at " << s << endl;
        delete s;
    }
    
    void addCharacter(const char c) {
        s->push_back(c);
    }

    void printIt() const {
        cout << *s << endl;
    }

    IHazStringPtr & operator=(const IHazStringPtr & other) {
        //if (other.s != nullptr) {
        
        //delete s;
        
        if (other.s) {
            s = new string(*(other.s));
        } else {
            s = nullptr;
        }
        
        return *this;
    }

};

int main() {

    IHazStringPtr foo;
    IHazStringPtr bar;

    
    /// foo and bar point to different strings
    
    bar = foo;
    
    // now point to the same string :(
    
    foo.addCharacter('a');
    bar.addCharacter('b');
    
    foo.printIt();
    bar.printIt();
}
