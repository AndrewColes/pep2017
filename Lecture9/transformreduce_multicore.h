#ifndef TRANSFORM_REDUCE_MULTICORE_H
#define TRANSFORM_REDUCE_MULTICORE_H

#include <iterator>
#include <algorithm>
#include <utility>

#include <omp.h>


template<typename ItrType,  typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce_imp1(ItrType wholeItr, ItrType wholeItrEnd,
                        T init, ReduceOp red, TransformOp trans,
                        std::random_access_iterator_tag) {
    
    
    auto span = (wholeItrEnd - wholeItr);;
    //std::cout << span << " elements total\n";
    
    auto threadCount = omp_get_max_threads();
    if (threadCount > span) {
        threadCount = span;
    }
    
    //std::cout << threadCount << " threads\n";
    span = span / threadCount;
    //std::cout << span << " elements per thread\n";
    
    
    auto toReturn = init;
    
    #pragma omp parallel for num_threads(threadCount)
    for (int i = 0; i < threadCount; ++i) {
        auto threadID = omp_get_thread_num();
        auto itr = wholeItr + (threadID * span);
        
        auto itrEnd = (i == threadCount - 1
                        ? wholeItrEnd 
                        : itr + span);
        
        auto localInit = init;
        
        //#pragma omp critical
        //{
        //    std::cout << "Thread " << threadID << ": [" << *itr << "," << *itrEnd << ")\n";
        //}
        
        for (; itr != itrEnd; ++itr) {
            localInit = red(localInit, trans(*itr));
        }
        
        #pragma omp critical
        {
            toReturn = red(toReturn, localInit);
        }
    }
    
    return toReturn;
}


template<typename ItrType,  typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce_imp1(ItrType itr, ItrType itrEnd,
                        T init, ReduceOp red, TransformOp trans,
                        std::forward_iterator_tag) {

    for (; itr != itrEnd; ++itr) {
        init = red(init, trans(*itr));
    }
    
    return init;
}


template<typename ItrType,  typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce(ItrType itr, ItrType itrEnd,
                   T init, ReduceOp red, TransformOp trans) {
    return transform_reduce_imp1(itr, itrEnd, init, red, trans, typename std::iterator_traits<ItrType>::iterator_category());
}


template<typename Itr1Type, typename Itr2Type,
         typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce_imp2(Itr1Type wholeItr, Itr1Type wholeItrEnd,
                        Itr2Type wholeOtherItr,
                        T init, ReduceOp red, TransformOp trans,
                        std::random_access_iterator_tag,
                        std::random_access_iterator_tag) {

    auto span = (wholeItrEnd - wholeItr);;
    //std::cout << span << " elements total\n";
    
    auto threadCount = omp_get_max_threads();
    if (threadCount > span) {
        threadCount = span;
    }
    
    //std::cout << threadCount << " threads\n";
    span = span / threadCount;
    //std::cout << span << " elements per thread\n";
    
    
    auto toReturn = init;
    
    #pragma omp parallel for num_threads(threadCount)
    for (int i = 0; i < threadCount; ++i) {
        auto threadID = omp_get_thread_num();
        auto itr = wholeItr + (threadID * span);
        auto otherItr = wholeOtherItr + (threadID * span);
        
        auto itrEnd = (i == threadCount - 1
                        ? wholeItrEnd 
                        : itr + span);
        
        auto localInit = init;
        
        //#pragma omp critical
        //{
        //    std::cout << "Thread " << threadID << ": [" << *itr << "," << *itrEnd << ")\n";
        //}
        
        for (; itr != itrEnd; ++itr, ++otherItr) {
            localInit = red(localInit, trans(*itr, *otherItr));
        }
        
        #pragma omp critical
        {
            toReturn = red(toReturn, localInit);
        }
    }
    
    return toReturn;
    
}



template<typename Itr1Type, typename Itr2Type,
         typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce_imp2(Itr1Type itr, Itr1Type itrEnd,
                        Itr2Type otherItr,
                        T init, ReduceOp red, TransformOp trans,
                        std::forward_iterator_tag,
                        std::forward_iterator_tag) {

    for (; itr != itrEnd; ++itr, ++otherItr) {
        init = red(init, trans(*itr, *otherItr));
    }
    
    return init;
}


template<typename Itr1Type, typename Itr2Type,
         typename T,
         typename ReduceOp, typename TransformOp>
T transform_reduce(Itr1Type itr, Itr1Type itrEnd,
                   Itr2Type otherItr,
                   T init, ReduceOp red, TransformOp trans) {
    return transform_reduce_imp2(itr, itrEnd, otherItr, init, red, trans,
                                 typename std::iterator_traits<Itr1Type>::iterator_category(),
                                 typename std::iterator_traits<Itr2Type>::iterator_category());
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
