//
// Created by zhaobo on 2022/2/21.
//
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

void print(int i) {
    cout << i << ' ';
}

class Int
{
public:
    explicit Int(int i) : m_i(i) { };
    void print1() const { cout << '[' << m_i << ']'; }

private:
    int m_i;
};

int main()
{
    ostream_iterator<int> outite(cout, " ");
    int ia[6] = { 2, 21, 12, 7, 19, 23 };
    vector<int> iv(ia, ia+6);
    cout << count_if(iv.cbegin(), iv.cend(), not1(bind2nd(less<int>(), 12)));
    cout << endl;
    //transform(iv.cbegin(), iv.cend(), outite, bind2nd(multiplies<int>(), 3), bind2nd(plus<int>(), 2));
}
