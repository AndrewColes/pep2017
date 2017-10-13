template<typename T>
class template_array {
  
private:
    
    T * elements;
    int arraySize;
    
public:

    
    template_array(const int s)
        : elements(new T[s]),
          arraySize(s) {
              
    }
    
    template_array(const template_array & toCopy) 
        : elements(new T[arraySize]),
          arraySize(toCopy.arraySize) {
              
        for (int i = 0; i < arraySize; ++i) {
            elements[i] = toCopy.elements[i];
        }
    }
    
    ~template_array() {
        delete [] elements;
    }
    
    T & operator[](const int idx) {
        return elements[idx];
    }
    
    const T & operator[](const int idx) const {
        return elements[idx];
    }
    
    int size() const {
        return arraySize;
    }
    
    bool operator==(const template_array & other) const {
        if (arraySize != other.arraySize) {
            return false;
        }
        
        for (int i = 0; i < arraySize; ++i) {
            if (other.elements[i] != elements[i]) {
                return false;
            }
        }
        return true;
    }
};

