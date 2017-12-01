#ifndef COUNTING_ITERATOR_H
#define COUNTING_ITERATOR_H

#include <iterator>
#include <cstdint>

/** @brief A counting iterator -- an integer in disguise
 *
 * This is an iterator that holds a value, but provides all the standard iterator functions
 * so it behaves just like an iterator over an infinitely long vector <code>vec</code>
 * where <code>vec[i] == i</code> for all elements of the vector.
 * 
 * This is a template class -- set the type to whatever you need.  Anything integral
 * is fine, e.g. an <code>int</code>, a <code>long</code>, a fixed-width int (e.g. <code>uint32_t</code>), and so on.
 * 
 * The following snippet prints out the numbers from 0 (inclusive) to 10 (exclusive):
 * 
 * \code
 * counting_iterator<int> itr(0);
 * const counting_iterator<int> itrEnd(10);
 * 
 * while (itr != itrEnd) {
 *     cout << *itr << "\n"; // prints out the current value of the iterator
 *     ++itr; // increments the current value of the iterator
 * }
 * \endcode 
 */
template<typename T>
class counting_iterator
{
private:
    T currentValue;

public:    
    
    typedef T value_type;
    typedef const T & reference;
    typedef const T * pointer;
    typedef int difference_type;
    typedef std::random_access_iterator_tag iterator_category;
    
    /** @brief Default constructor -- does not initialise the value */
    counting_iterator() {
    }

    /** @brief Create a counting_iterator with the specified value */
    counting_iterator(const T in) 
        : currentValue(in) {
    }
    
    /** @brief Get the current value of the counting_iterator */
    reference operator*() const {
        return currentValue;
    }

    
    /** @brief Increment the value of the counting iterator */
    counting_iterator & operator++() {
        ++currentValue;
        return *this;
    }

    counting_iterator operator++(int) {
        counting_iterator toReturn(currentValue);        
        ++currentValue;
        return toReturn;
    }
    
    counting_iterator & operator--() {
        --currentValue;
        return *this;
    }
        
    counting_iterator operator--(int) {
        counting_iterator toReturn(currentValue);        
        --currentValue;
        return toReturn;
    }
    
    bool operator==(const counting_iterator & other) const {
        return currentValue == other.currentValue;
    }
    
    bool operator!=(const counting_iterator & other) const {
        return currentValue != other.currentValue;
    }
        
    
    counting_iterator & operator+=(const difference_type n) {
        currentValue += n;
        return *this;
    }
    
    counting_iterator operator+(const difference_type n) const {
        return counting_iterator(currentValue + n);
    }

    
    counting_iterator & operator-=(const difference_type n) {
        currentValue -= n;
        return *this;
    }        

    value_type operator[](const difference_type n) const {
        return currentValue + n;
    }
    
    bool operator<(const counting_iterator & other) const {
        return (currentValue < other.currentValue);
    }
    
    bool operator>(const counting_iterator & other) const {
        return (currentValue > other.currentValue);
    }
    
    bool operator<=(const counting_iterator & other) const {
        return (currentValue <= other.currentValue);
    }
    
    bool operator>=(const counting_iterator & other) const {
        return (currentValue >= other.currentValue);
    }
};

template<typename T>
counting_iterator<T> operator+(const typename counting_iterator<T>::difference_type n,
                               counting_iterator<T> itr) {
    itr += n;
    return itr;
}


template<typename T>
typename counting_iterator<T>::difference_type operator-(const counting_iterator<T> & itrOne,
                                                         const counting_iterator<T> & itrTwo) {
    return (*itrOne - *itrTwo);
}


#endif
