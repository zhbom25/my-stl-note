#include <cstddef>
#include <istream>
#include <iostream>
using namespace std;

//
// Created by zhaobo on 2022/2/22.
//
template <typename T, typename Distance = ptrdiff_t>
class istream_iterator {
    friend bool operator== (const istream_iterator<T, Distance>& x,
            const istream_iterator<T, Distance>& y);

protected:
    istream* stream;
    T value;
    bool end_marker;
    void read() {
        end_marker = (*stream) ? true : false;
        if (end_marker) *stream >> value;
        end_marker = (*stream) ? true : false;
    }

public:
    typedef input_iterator_tag iterator_category;
    typedef T value_type;
    typedef Distance difference_type;
    typedef const T* pointer;
    typedef const T& reference;
    istream_iterator() : stream(&cin), end_marker(false) {}
    istream_iterator(istream& s) : stream(&s) { read(); }
    reference operator*() const { return value; }
    pointer operator->() const { return &(operator*());}

    istream_iterator<T, Distance>& operator++() {
        read();
        return *this;
    }
    istream_iterator<T, Distance> operator++(int) {
        istream_iterator<T, Distance> tmp = *this;
        read();
        return tmp;
    }
};