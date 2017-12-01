#ifndef TRANSFORM_REDUCE_SINGLECORE_H
#define TRANSFORM_REDUCE_SINGLECORE_H

/** @brief Transform each element in the given range using <code>trans</code>, combining the results of this together using <red>
 * 
 * This takes a pair of iterators, <code>itr</code> and <code>itrEnd</code>; and an initial 'answer so far', <code>init</code>
 * 
 * If <code>itr == itrEnd</code>, it does nothing, and just returns <code>init</code>.
 * 
 * Otherwise, for each element from <code>itr</code>
 * (inclusive) to <code>itrEnd</code> (exclusive), it apples the given transformation function, <code>trans</code>; then combines the result of this with the answer so far, using <code>red</code>.
 *
 * For instance, if we wanted to take 'mod 5' of each number in a vector, then take the sum of these, we could write:
 * 
 * \code
 * vector<int> numbers{1,4,19,42,3,7};
 * int sumOfModFives = transform_reduce(
 *     numbers.begin(), numbers.end(),   // the range to loop over
 *     0,                                // the initial answer so far (i.e. the case for an empty range of numbers)
 *     [](const int soFar,               // the reduction lambda: take the answer so far, 
 *        const int afterTransform) {    // and add the result of the current transform
 *         return soFar + afterTransform;
 *     },
 *     [](const int curr) {              // the transform lambda: it's called with a number from the input range
 *         return curr % 5;              // ...then takes 'mod 5' and returns it
 *     });
 * 
 * \endcode
 *
 */ 
template<typename ItrType,  typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce(ItrType itr, ItrType itrEnd,
                   T init, ReduceOp red, TransformOp trans) {

    for (; itr != itrEnd; ++itr) {
        init = red(init, trans(*itr));
    }
    
    return init;
}


template<typename Itr1Type, typename Itr2Type,
         typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce(Itr1Type itr, Itr1Type itrEnd,
                   Itr2Type otherItr,
                   T init, ReduceOp red, TransformOp trans) {

    for (; itr != itrEnd; ++itr, ++otherItr) {
        init = red(init, trans(*itr, *otherItr));
    }
    
    return init;
}

template<typename Itr1Type, typename Itr2Type,
         typename T>
T transform_reduce(Itr1Type itr, Itr1Type itrEnd,
                   Itr2Type otherItr,
                   T init) {
    
    typedef decltype(*itr) aType;
    typedef decltype(*otherItr) bType;
    typedef decltype(*itr + *otherItr) sumType;
    
    return transform_reduce(itr, itrEnd, otherItr, 
                            init,
                            [](const T & a, const sumType & b) {
                                return a + b;
                            },
                            [](const aType & a, const bType & b) {
                                return a * b;
                            });
}

#endif
