//
// Created by zhaobo on 2022/2/11.
//

#ifndef STL_TEST_1_9_4_H
#define STL_TEST_1_9_4_H

#include <iostream>
using namespace std;

class INT
{
    friend ostream& operator<<(ostream& os, const INT& i);

public:
    INT(int i) : m_i(i) { };

    INT& operator++() {
        ++(this->m_i);
        return *this;
    }

    const INT operator++(int)
    {
        INT temp = *this;
        ++(*this);
        return temp;
    }

    INT& operator--()
    {
        --(this->m_i);
        return *this;
    }

    const INT operator--(int)
    {
        INT temp = *this;
        --(*this);
        return temp;
    }

    int& operator*() const
    {
        return (int&)m_i;
    }

private:
    int m_i;
};

ostream& operator<<(ostream& os, const INT& i)
{
    os << '[' << i.m_i << ']';
    return os;
}

#endif //STL_TEST_1_9_4_H
