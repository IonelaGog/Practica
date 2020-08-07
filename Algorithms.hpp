#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <cstddef>
#include <cstdlib>

namespace pdv{
    template <typename TInputIt, typename TOutputIt>
    TOutputIt copy(TInputIt first, TInputIt last, TOutputIt output){
        for (TInputIt it = first; it != last; ++it){
          *output++ = *it;
        }
        
        return output;
    }

    template <typename TInputIt, typename TOutputIt>
    TOutputIt move(TInputIt first, TInputIt last, TOutputIt output){
        for (TInputIt it = first; it != last; ++it){
          *output++ = std::move(*it);
        }
        
        return output;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    TOutputIt copyIf(TInputIt first, TInputIt last, TOutputIt output, TPredicate pred){
        for (TInputIt it = first; it != last; ++it){
            if (pred(*it) == true){  
              *output++ = *it;
            }
        }

        return output;
    }

    template <typename TInputIt, typename TOutputIt, typename TValue>
    TInputIt find(TInputIt first, TInputIt last, TValue value){
        while (first != last){
            if (*first == value) 
                return first;
            
            ++first;
        }
        return last;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    TInputIt findIf(TInputIt first, TInputIt last, TPredicate pred){
        while (first != last){
            if (pred(*first)) 
                return first;
          ++first;
        }
        return last;
    }

    template <typename TInputIt, typename TOutputIt, typename TValue>
    std::size_t count(TInputIt first, TInputIt last, TValue value){
        std::size_t cnt = 0;
        
        for (TInputIt it = first; it != last; ++it){
            if(*it == value){
                ++cnt;
            }
        }
        return cnt;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    std::size_t countIf(TInputIt first, TInputIt last, TPredicate pred){
        std::size_t cnt = 0;
        
        for (TInputIt it = first; it != last; ++it){
            if(pred(*it)){
                ++cnt;
            }
        }
        return cnt;
    } 

    template <typename TInputIt, typename TOutputIt, typename TValue>
    void fill(TInputIt first, TInputIt last, TValue value){
        for (TInputIt it = first; it != last; ++it){
            *it = value;
        }
    }

    template <typename TInputIt, typename TOutputIt, typename TComparator>
    void sort(TInputIt first, TInputIt last, TComparator comp){

        for (TInputIt i = first; first != last-1; ++first){
            for (TInputIt j = i+1; j != last; ++j){
                if (comp(*i, *j)){
                    std::swap(*i, *j);
                }
            }
        }
    }

    template <typename TLhsInputIt, typename TInputIt, typename TRhsInputIt>
    bool equal(TLhsInputIt lhsFirst, TInputIt lhsLast, TRhsInputIt rhsFirst){
        for(TLhsInputIt itL = lhsFirst; itL != lhsLast; ++itL){
            for(TRhsInputIt itR = rhsFirst; itR != lhsLast; ++itR){
                if(!(*itL == *itR)){
                    return false;
                }
            }
        }
      return true;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    bool anyOf(TInputIt first, TInputIt last, TPredicate pred){
        for (TInputIt it = first; it != last; ++it){
            if(pred(*it)){
                return true;
            }
        }
        return false;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    bool allOf(TInputIt first, TInputIt last, TPredicate pred){
        for (TInputIt it = first; it != last; ++it){
             if(!pred(*it)){
                return false;
            }
        }
        return true;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    bool noneOf(TInputIt first, TInputIt last, TPredicate pred){
        for (TInputIt it = first; it != last; ++it){
            if(pred(*it)){
                return false;
            }
        }
        return true;
    }

    template <typename TInputIt, typename TOutputIt, typename TUnaryFunc>
    TOutputIt transform(TInputIt first, TInputIt last, TOutputIt output, TUnaryFunc func){
        for (TInputIt it = first; it != last; ++it){
            *output++ = func(*it);
        }
        return output;
    }

    template <typename TInputIt, typename TOutputIt, typename TValue, typename TBinaryFunc>
    TValue reduce(TInputIt first, TInputIt last, TValue initValue, TBinaryFunc func){
        for (TInputIt it = first; it != last; ++it){
            initValue = func(*it, initValue);
        }
        return initValue;
    }
}

#endif //ALGORITHMS_HPP