/*
 Part of Cosmos by OpenGenus Foundation
 Ternary Search Uses Divide And Conquer Technique
 */

#include <iterator>
template<typename _RandomAccessIter,
         typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type>
_RandomAccessIter
ternarySearch(_RandomAccessIter first,
              _RandomAccessIter last,
              const _RandomAccessIter notFoundSentinel,
              const _ValueType &x){
    if(last>=first){
        auto mid1 = first + (last-first)/3;
        auto mid2 = last - (last-first)/3;
        if(*mid1 == x)
            return mid1;
        if(*mid2 == x)
            return mid2;
        if(x<*mid1)
            return ternarySearch(first,mid1-1, notFoundSentinel,x);
        else if(x>*mid2)
            return ternarySearch(mid2+1,last, notFoundSentinel,x);
        else
            return ternarySearch(mid1+1,mid2-1, notFoundSentinel,x);
    }
    return notFoundSentinel; // if x is not found in array arr
}

template<typename _RandomAccessIter,
         typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type>
_RandomAccessIter
ternarySearch(_RandomAccessIter begin, _RandomAccessIter end, const _ValueType&x)
{
    if (begin < end)
    {
        auto res = ternarySearch(begin, end - 1, end, x);

        return res == end ? end : res;
    }

    return end;
}
