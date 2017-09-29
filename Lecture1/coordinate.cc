#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

class Coordinate {

protected:
    int x;
    int y;
    
public:
    
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
    
    Coordinate operator+(Coordinate c) const {
        return Coordinate(x + c.x,
                          y + c.y);
    }
    
    Coordinate operator*(int scaleFactor) const {
        return Coordinate(x * scaleFactor,
                          y * scaleFactor);
    }
    
    
};


void moveXToZero(Coordinate & c) {
    c.setX(0);
}

class Journey {
  
protected:
    
    Coordinate start;
    Coordinate end;
    
    double distance;
    
    void recalculateDistance() {
        // does the pythag thing to set distance
    }
    
public:
    
    Journey(Coordinate startIn, Coordinate endIn)
        : start(startIn),
          end(endIn) {
              
        recalculateDistance();      
    }
    
    const Coordinate & getStart() const {
        return start;
    }
    
    void setStart(Coordinate startIn) {
        start = startIn;
        recalculateDistance();
    }
};

void printX(const Coordinate & c) {
    cout << c.getX() << std::endl;
    //c.setX(10);
}



ostream & operator<<(ostream & o,
                     const Coordinate & rhs) {

    o << "(" << rhs.getX() << "," << rhs.getY() << ")";
    return o;
}

int main() {
    Coordinate a(4,-3);
    
    Coordinate b(4,-3);
    
    
    cout << a.getX() << std::endl;
    
    Journey trip(Coordinate(0,0), Coordinate(10,8));
    
    const Coordinate & myOwnCopy = trip.getStart();
    //myOwnCopy.setX(9001);
    
    const Coordinate cannotChange(1,2);
    
    cout << "Coordinate a: " << a << endl;
    
}

