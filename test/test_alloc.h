//
// Created by zhaobo on 2022/2/14.
//

#ifndef STL_TEST_ALLOC_H
#define STL_TEST_ALLOC_H
#include <stdlib.h>
#include <stddef.h>
#include <iostream>

template <typename T>
class TestAlloc {
public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference;

public:
    TestAlloc() {};
    TestAlloc(const TestAlloc<T> &); // 拷贝构造函数
    ~TestAlloc(); // 析构函数

    // 返回某个对象的地址，a.address(x)等同于&x
    pointer address(reference x) const {
        return &x;
    }

    // 返回某个const对象的地址，a.address(x)等同于&x
    const_pointer address(const_reference x) const {
        return &x;
    }

    // 配置空间，足以存储n个T对象。第二个参数是个提示。实现上可能会利用它来增进区域性(locality)，或完全忽略之
    pointer allocate(size_type n, const void * = 0) {
        T* tmp = (T*)(::operator new ((size_t)(n * sizeof (T))));
        if (tmp == 0) {
            std::cerr << "out of memory" << std::endl;
            exit(1);
        }
        return tmp;
    }

    // 释放先前配置的空间
    void deallocate(pointer p, size_type n) {
        ::operator delete(p);
    }

    // 返回可成功配置的最大量
    size_type maxsize() {
        return (size_type) (UINT32_MAX / sizeof(T));
    }

    // 调用对象的构造函数，等同于 new((void*)p) T(x)
    void construct(pointer p, const T &x) {
        new (p) T(x);
    }

    // 调用对象的析构函数，等同于 p->~T()
    void destroy(pointer p) {
        p->~T();
    }
};
#endif //STL_TEST_ALLOC_H
