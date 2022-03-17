//
// Created by zhaobo on 2022/2/11.
//

#ifndef STL_TEST_1_9_6_H
#define STL_TEST_1_9_6_H

#include <iostream>
using namespace std;

template <class T>
struct Plus {
    T operator() (const T& x, const T& y) {return x+y;}
};

template <class T>
struct Minus {
    T operator() (const T& x, const T& y) {return x-y;}
};

#endif //STL_TEST_1_9_6_H
