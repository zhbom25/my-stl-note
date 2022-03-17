//
// Created by zhaobo on 2022/2/15.
//

#ifndef STL_MITER_H
#define STL_MITER_H

#include "mitem.h"

template <typename Item>
class MIter {
    MIter<Item>() : _ptr(nullptr) {}
    MIter<Item>(Item* p = nullptr) : _ptr(p) {}
    Item& operator *() {
        return *_ptr;
    }
    Item* operator ->() {
        return _ptr;
    }
    MIter<Item>& operator ++() {
        _ptr = _ptr->next();
        return *this;
    }
    MIter<Item> operator ++(int) {
        MIter tmp = *this;
        ++*this;
        return tmp;
    }
    bool operator ==(const MIter<Item>& iter) {
        return (_ptr == iter._ptr);
    }
    bool operator !=(const MIter<Item>& iter) {
        return (_ptr != iter._ptr);
    }
private:
    Item* _ptr;
};
#endif //STL_MITER_H
