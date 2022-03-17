//
// Created by zhaobo on 2022/2/15.
//

#ifndef STL_MITEM_H
#define STL_MITEM_H

template <typename T>
class MListItem {
public:
    MListItem<T>() : _value(nullptr), _next(nullptr) {}
    MListItem<T>(const T& val) {
        _value = new T(val);
        _next = nullptr;
    }
    MListItem<T>(const T& val, MListItem<T>* next) {
        _value = new T(val);
        _next = next;
    }
    MListItem<T>(MListItem<T>& item) {
        _value = new T(item.value());
        _next = item.next();
    }
    MListItem<T>& operator=(const MListItem<T>& item) {
        if (this == &item) return *this;
        if (_value != nullptr) delete(_value);
        if (_next != nullptr) delete(_next);
        _value = new T(item.value());
        _next = item.next();
        return *this;
    }
    T& value() {
        return *_value;
    }
    MListItem<T>* next() {
        return _next;
    }
    T& operator *() {
        return *_value;
    }
    void addNext(const T& val) {
        MListItem<T>* node = new MListItem<T>(val);
        _next = node;
    }
    void addNext(MListItem<T>* node) {
        _next = node;
    }
    MListItem<T>& operator ++() {
        if (this->_value != nullptr) {
            _value = &(_next->value());
            _next = _next->next();
        }
        return *this;
    }
    MListItem<T>& operator ++(int) {
        if (this) {
            MListItem<T>* tmp = this;
            this = this->_next;
            return *tmp;
        } else {
            return nullptr;
        }
    }

private:
    T*              _value;
    MListItem<T>*   _next;
};

template <typename T>
bool operator ==(MListItem<T> &item1, MListItem<T> &item2) {
    if (item1.value() == item2.value() && item1.next() == item2.next()) {
        return true;
    } else {
        return false;
    }
}
template <typename T>
bool operator !=(MListItem<T> &item1, MListItem<T> &item2) {
    return !(item1 == item2);
}

#endif //STL_MITEM_H
