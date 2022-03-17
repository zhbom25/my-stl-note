//
// Created by zhaobo on 2022/2/15.
//

#ifndef STL_MLIST_H
#define STL_MLIST_H

#include <cstdlib>
#include <iostream>
#include "mitem.h"

template <typename T>
class MList {
public:
    MList<T>() : _front(nullptr), _end(nullptr), _size(0) {
        _END = new MListItem<T>(-1, nullptr);
    }

    MList<T>(MListItem<T>& begin, MListItem<T>& end) {
        while (begin != end) {
            push_back(begin->value());
            begin++;
        }
        _END = new MListItem<T>(-1, nullptr);
    }
    ~MList<T>() {
        if (_end != nullptr) {
            while (_front != _end->next()) {
                auto cur = _front;
                _front = _front->next();
                delete (cur);
            }
        }
        if (_END) delete (_END);
        _size = 0;
    }
    MListItem<T>& front() {
        if (_front != nullptr) {
            return *_front;
        } else {
            return nullptr;
        }
    }
    void push_back(const T& val) {
        if (_end) {
            _end->addNext(val);
            _end = _end->next();
        } else {
            MListItem<T>* node = new MListItem<T>(val);
            _front = _end = node;
        }
        _end->addNext(_END);
        _size++;
    }
    MListItem<T>& begin() {
        return *_front;
    }
    MListItem<T>& end() {
        return *_END;
    }
    size_t size() {
        return _size;
    }
    void display(std::ostream &os = std::cout) const {
        if (_size == 0) return;
        MListItem<T>* cur = _front;
        while (cur != _END) {
            os << cur->value() << std::endl;
            cur = cur->next();
        }
    }

private:
    MListItem<T>*   _front;
    MListItem<T>*   _end;
    size_t          _size;
    MListItem<T>*   _END;
};
#endif //STL_MLIST_H
