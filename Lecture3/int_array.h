class int_array {
  
private:
    
    int * elements;
    int arraySize;
    
public:

    
    class iterator {
    public:
        
        int * ptr;
        
        iterator(int * data)
            : ptr(data) {
        }
        
        int & operator*() {
            return *ptr;
        }
        
        iterator & operator++() {
            ++ptr;
            return *this;
        }
        
        bool operator!=(const iterator & other) const {
            return (ptr != other.ptr);
        }
        
        
        bool operator==(const iterator & other) const {
            return (ptr == other.ptr);
        }
    };
    
    int_array(const int s)
        : elements(new int[s]),
          arraySize(s) {
              
    }
    
    int_array(const int_array & toCopy) 
        : elements(new int[arraySize]),
          arraySize(toCopy.arraySize) {
              
        for (int i = 0; i < arraySize; ++i) {
            elements[i] = toCopy.elements[i];
        }
    }
    
    ~int_array() {
        delete [] elements;
    }
    
    int & operator[](const int idx) {
        return elements[idx];
    }
    
    const int & operator[](const int idx) const {
        return elements[idx];
    }
    
    int size() const {
        return arraySize;
    }
    
    iterator begin() {
        return iterator(elements);
    }
    
    iterator end() {
        return iterator( &(elements[arraySize]) );
    }
};

