#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;

#include <string>
using std::string;

class Coordinate {

public:
    int x;
    int y;
    
    Coordinate(int xIn, int yIn)
        : x(xIn), y(yIn) {            
        //x = xIn;
        //y = yIn;
    }
    
    Coordinate()
        : x(0), y(0) {
    }
    
    void setX(int newX) {
        x = newX;
    }
    
    int getX() const {
        return x;
    }
    
    int getY() const {
        return y;
    }
    
    bool operator==(const Coordinate & c) const {
        return (x == c.x && y == c.y);
    }
    

    void write(ostream & o) const {
        o << x << "," << y;
    }
    
    virtual void printDetails() const {
        cout << x << "," << y;
    }
    
};





ostream & operator<<(ostream & o,
                     const Coordinate & rhs) {
    rhs.write(o);
    return o;
}


class Bikes : public Coordinate {
  
protected:
    int howMany;
    
public:
    
    Bikes(const int xIn, const int yIn,
          const int howManyIn)
        : Coordinate(xIn, yIn),
          howMany(howManyIn) {
              
    }
    
    int getHowMany() const {
        return howMany;
    }
    
    virtual void printDetails() const override {
        Coordinate::printDetails();
        cout << ": " << howMany << " bikes";
    }
};

void someFunction(const Coordinate & c) {
    c.printDetails();
    cout << "\n";
}

void letsFindOut(Coordinate * c) {
    Bikes * b = dynamic_cast<Bikes*>(c);
    if (b) {
        cout << b->getHowMany() << "\n";
    } else {
        cout << "c isn't a Bikes object, silly\n";
    }
}

int main() {

    Coordinate c(3,4);    
    //|  vtableptr  |  3  |  4  |
    
    
    
    Bikes notBoris(10,10,
                   40);
    //|  vtableptr  |  10  | 10 |  40 |
    
    
    cout << "notBoris.printDetails(): ";
    notBoris.printDetails();
    cout << "\n";
    
    // here be dragons...
    
    cout << "Coordinate * messWithB = &notBoris;\nCalling messWithB->printDetails() gets: ";
    Coordinate * messWithB = &notBoris;
    messWithB->printDetails();
    cout << "\n";
    cout << "...which is fine, it shows the virtual function is working\n\n";
    
    
    auto vTableForC = reinterpret_cast<void**>(&c);
    
    cout << "C   is at " << &c << "\n";
    cout << "C.x is at " << &(c.x) << "\n";
    cout << "Before C.x is the v table pointer: " << *vTableForC << "\n";
    cout << "\n";
    
    auto vTableForB = reinterpret_cast<void**>(messWithB);
    
    cout << "notBoris   is at " << &notBoris << "\n";
    cout << "notBoris.x is at " << &(notBoris.x) << "\n";
    cout << "Before notBoris.x is the v table pointer: " << *vTableForB << "\n";
    cout << "\n";
    
    
    *vTableForB = *vTableForC;
    
    cout << "After assignment, its v table pointer is: " << *vTableForB << "\n";    
    
    cout << "Calling messWithB->printDetails() now gets: ";
    messWithB->printDetails();
    cout << "\n";
    
    cout << "Calling notBoris.printDetails() still gets: ";
    notBoris.printDetails();
    cout << "\n";
}
