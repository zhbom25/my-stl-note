//
// Created by zhaobo on 2022/2/11.
//

#ifndef STL_CONFIG10_H
#define STL_CONFIG10_H

#include <iostream>
#include <cstddef>

using namespace std;

class alloc {
};

template <typename T, typename Alloc = alloc, size_t BufSiz = 0>
class deque {
public:
    deque() {
        cout << "deque" << endl;
    }
};

template <typename T, typename Sequence = deque<T> >
class stack {
public:
    stack() {
        cout << "stack" << endl;
    }
private:
    Sequence c;
};

#endif //STL_CONFIG10_H
