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





ostream & operator<<(ostream & o,
                     const Coordinate & rhs) {

    o << "(" << rhs.getX() << "," << rhs.getY() << ")";
    return o;
}



template<typename T>
class unique_ptr {
  
private:
    T* data;
    
public:
    
    unique_ptr() : data(nullptr) {}
    
    unique_ptr(T* dataIn) : data(dataIn) {}
    
    ~unique_ptr() { delete data; }
    
    T & operator*() const {
        return *data;
    }
    
    T & operator->() const {
        return *data;
    }
    
    
    
};




int main() {
    
    unique_ptr<Coordinate> c(new Coordinate(3,4));
    cout << *c << endl;
}

