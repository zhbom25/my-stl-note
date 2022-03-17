//
// Created by zhaobo on 2022/2/11.
//

#ifndef STL_TEST_1_9_2_H
#define STL_TEST_1_9_2_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class print
{
public:
    void operator() (const T& elem) {
        cout << elem << ' ';
    }
};

#endif //STL_TEST_1_9_2_H
