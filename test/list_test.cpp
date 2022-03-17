//
// Created by zhaobo on 2022/2/15.
//

#include "mitem.h"
#include "mlist.h"
#include "miter.h"
#include "mfind.h"
#include <vector>
#include <set>

using namespace std;

int test_f(int val)
{
    return val += 5;
}

template <typename Iterator, typename Func>
int count_f(Iterator first, Iterator last, Func func);

template <typename T>
struct plus2{
    void operator() (T& x) const {
        x += 2;
    }
};

template <typename T>
struct print_s {
    void operator() (const T& x) {
        cout << "val : " << x << endl;
    }
};

int main(int argc, char** argv) {
    /*
    //std::cout << vector<int>::iterator::iterator_category() << endl;
    MList<int> mlist;
    vector<int> vec = {1,2,3,4,4,5,6,7,8,9,0,-1,-1};
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        mlist.push_back(*iter);
    }
    cout << "===display===" << endl;
    mlist.display();
    cout << "===iter===" << endl;
    for (auto iter = mlist.begin(); iter != mlist.end(); ++iter) {
        cout << *iter << endl;
    }
    cout << "yyyy" << endl;
    auto iter = mlist.end();
    cout << "xxxx" << endl;
    cout << *iter << endl;
    /*
    auto iter = mlist.begin();
    int i = 0;
    while (i < 10) {
        cout << *iter << endl;
        ++iter;
        i++;
    }
    cout << "hello" << endl;
     */
    //int val = 10;
    //cout << "ret val : " << test_f(val) << endl;
    /*
    int ia[] = {22,30,30,17,33,40,17,23,22,12,20};
    vector<int> iv(ia, ia+sizeof(ia)/sizeof(int));
    auto iter1 = iv.begin();
    auto iter2 = iv.end();
    sort(iter1,iter2);
    for (auto v : iv) {
        cout << "val : " << v << endl;
    }
    cout << "=========" << endl;
    for_each(iter1, iter2, plus2<int>());
    for (auto v : iv) {
        cout << "val : " << v << endl;
    }
    cout << "=====mset=====" << endl;
    set<int> mset = {2,3,4,6,1,5,9,7,8,12,10,11};
    for (auto iter = mset.cbegin(); iter != mset.cend(); ++iter) {
        cout << "val : " << *iter << endl;
        cout << "type : " << typeid(*iter).name() << endl;
    }
    auto iter3 = mset.begin();   // set返回的迭代器是const
    auto iter4 = mset.end();
    for_each(iter3, iter4, print_s<int>());
     */
    int ia[] = {22,30,30,17,33,40,17,23,22,12,20};
    vector<int> iv(ia, ia+sizeof(ia)/sizeof(int));
    auto iter1 = iv.cbegin();
    auto iter2 = iv.cend();

    //count(iter1,iter2,not1(bind2nd(less<int>(), 12)));
    //auto f = not1(bind2nd(less<int>(), 12));
    auto f = [](int val){
        //cout << "goon" << endl;
        if (val > 25) return true;
        else return false;
    };
    //cout << f(30) << endl;
    cout << count_f(iter1, iter2, f) << endl;
    return 0;
}

template <typename Iterator, typename Func>
int count_f(Iterator first, Iterator last, Func func) {
    int result = 0;
    while (first != last) {
        if (func(*first)) {
            result++;
        }
        ++first;
    }
    return result;
}

