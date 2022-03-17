//
// Created by zhaobo on 2022/2/15.
//

#ifndef STL_MFIND_H
#define STL_MFIND_H

#include "mitem.h"
#include "mlist.h"
#include "miter.h"

template <typename InputIterator, typename T>
InputIterator mfind(InputIterator beg, InputIterator end, const T& val) {
    while (beg != end && *beg != val) {
        beg++;
    }
    return beg;
}
#endif //STL_MFIND_H
