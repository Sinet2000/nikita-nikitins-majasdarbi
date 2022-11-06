#ifndef math_utils_h
#define math_utils_h

#include "program_utils.h"
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h> //sqrt
#include <tuple>

using namespace std;

namespace mathUtils {

    template <typename T>
    struct MinAndMaxValue {
        T *minValue;
        T *maxValue;
    };

    template<typename T, typename U>
    typename std::common_type<T, U>::type sum(T const& a, U const& b) {
        return a + b;
    }
    
    template<typename T>
    bool compareDataPtrValues(T *a, T *b) {
        return (*a < *b);
    }

    template<typename T>
    MinAndMaxValue<T> getMinAndMax(vector<T*> valueVector) {
        MinAndMaxValue<T> minAndMaxValue;

        sort(valueVector.begin(), valueVector.end(), mathUtils::compareDataPtrValues<T>);

        minAndMaxValue.minValue = valueVector.front();
        minAndMaxValue.maxValue = valueVector.back();

        return minAndMaxValue;
    }

    bool isPrimeNumber(int const& number) {
        
        if (number <= 1)
            return false;

        int k = 0;
        // improved logic:
        /**
        * Pieņemsim skaitli N, kas ir naturāls skaitlis (>1),
        * kas ir products no skaitļa a un b reizināšanas (a<=b pieņemsim),
        * tad N = a *b, kur 1<a<=b<n,
        * reizinot ar a, tad:
        * a^2<=ab
        * ar b, tad => ab<=b^2
        * tad intervaals ir => a^2<=ab<=b^2, bet ir zinaams, ka ab = N, taapeec:
        * a<= sqrt(N) <= b
        **/
        for (int i = 2; i <= sqrt(number) ; i++)
        {
            if (number % i == 0)
                k ++;
        }

        return !(k > 0);
    }

};

#endif