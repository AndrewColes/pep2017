#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;

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
    
    Bikes(const int xIn, const int yIn, const int howManyIn)
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
    
    cout << &c << endl;
    cout << &(c.x) << endl;
    cout << &(c.y) << endl;
    
    cout << "----\n";
    
    Bikes notBoris(10,20,40);
    
    notBoris.printDetails();
    cout << "\n";
    
    someFunction(notBoris);
    
    vector<Coordinate> oops;
    oops.push_back(Coordinate(0,0));
    oops.push_back(Coordinate(1,0));
    oops.push_back(Coordinate(2,0));
    
    vector<unique_ptr<Coordinate> > phew;    
    phew.emplace_back(new Coordinate(0,0));
    
    
    //phew.push_back(unique_ptr<Coordinate>(new Coordinate(0,0)));
    
    //phew[0] = unique_ptr<Coordinate>(new Coordinate(0,0));
    
    /*(3);
    phew[0].reset(new Coordinate(0,0));
    phew[1].reset(new Bikes(10,4,100));
    phew[2].reset(new Coordinate(0,0));*/

    letsFindOut(&notBoris);
    letsFindOut(&c);
}
