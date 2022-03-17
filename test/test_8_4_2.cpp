//
// Created by zhaobo on 2022/2/22.
//
#include <functional>

template <typename Operation>
class binder1st : public std::unary_function<typename Operation::second_argument_type,
        typename Operation::result_type> {
protected:
    Operation op;
    typename Operation::first_argument_type value;

public:
    binder1st(const Operation &x, const typename Operation::first_argument_type &y) : op(x), value(y) {}

    typename Operation::result_type operator()(const typename Operation::second_argument_type &x) const {
        return op(value, x);
    }
};

/*
template <class Operation, class T>
inline binder1st<Operation> binder1st(const Operation& op, const T& x)
{
    typedef typename Operation::first_argument_type arg1_type;
    return binder1st<Operation>(op, arg1_type(x));
}
 */

template <typename Operation>
class binder2nd : public std::unary_function<typename Operation::first_argument_type,
        typename Operation::result_type> {
protected:
    Operation op;
    typename Operation::second_argument_type value;
public:
    binder2nd(const Operation& x, const typename Operation::second_argument_type& y) : op(x), value(y) {}
    typename Operation::result_type operator()(const typename Operation::first_argument_type& x) const {
        return op(x, value);
    }
};

template <typename Operation, typename T>
inline binder2nd<Operation> bind2nd(const Operation& op, const T& x)
{
    typedef typename Operation::second_argument_type arg2_type;
    return binder2nd<Operation>(op, arg2_type(x));
}
