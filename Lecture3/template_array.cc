#include "template_array.h"

class SmallClass {
public:
    
    int x;
    int y;
    
    SmallClass(int xIn, int yIn) 
        : x(xIn),
          y(yIn) {
    }
};

int main() {
    template_array<int>    wholeNumbers(10);
    
    template_array<double> floatingPointNumbers(5);
    template_array<char>   characters(2);

    // template_array<SmallClass>  lookAtThis(3); // doesn't work unless we add a default c'tor to SmallClass
    
}
