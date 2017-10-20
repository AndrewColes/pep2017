#include <memory>
using std::unique_ptr;
#include <vector>
#include <iostream>
using std::vector;
using std::cout;

#include <algorithm>
using std::max;

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
    
    bool operator<(const Coordinate & c) const {
        return (x < c.x);
    }
    
};

unique_ptr<Coordinate> threeFour() {
    return unique_ptr<Coordinate>(new Coordinate(3,4));
}

class CompareByY {
  
public:
    
    bool operator()(const Coordinate & a, const Coordinate & b) const {
        return (a.getY() < b.getY());
    }
};

bool ohai(const Coordinate & a, const int & b) {
    cout << "Ohai -- inside the function\n";
    return true;
}


    
int main() {
    unique_ptr<Coordinate> a(new Coordinate(1,2));
    a = threeFour();
    
    unique_ptr<Coordinate> b(threeFour());
    
    vector<int> numbers(1000000);    
    cout << "Numbers points to " << numbers.data() << "\n";
    
    vector<int> moarNumbers(std::move(numbers));
    
    cout << "Numbers points to " << numbers.data() << "\n";
    cout << "MoarNumbers points to " << moarNumbers.data() << "\n";
    
    cout << numbers.size() << "\n";
    cout << moarNumbers.size() << "\n";
    
    
    Coordinate smallerX(0,10);
    Coordinate biggerX(10,3);
    
    Coordinate theBiggest = max(smallerX, biggerX);
    
    Coordinate theBiggestByY = max(smallerX, biggerX, CompareByY());

    CompareByY ohai;

    
    bool returnValue = ::ohai(smallerX, 7);
    
}
