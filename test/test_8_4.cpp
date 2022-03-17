//
// Created by zhaobo on 2022/2/22.
//
#include <functional>

template <class Predicate>
class unary_negate : public std::unary_function<typename Predicate::argument_type, bool> {
protected:
    Predicate pred;
public:
    explicit unary_negate(const Predicate& x) : pred(x) {}
    bool operator() (const typename Predicate::argument_type& x) const {
        return !pred(x);
    }
};

template <class Predicate>
inline unary_negate<Predicate> not1(const Predicate& pred) {
    return unary_negate<Predicate>(pred);
}

template <typename Predicate>
class binary_negate : public std::binary_function<
        typename Predicate::first_argument_type,
        typename Predicate::second_argument_type, bool> {
protected:
        Predicate pred;
public:
        explicit binary_negate(const Predicate& x) : pred(x) {}
        bool operator() (const typename Predicate::first_argument_type& x,
                const typename Predicate::second_argument_type& y) const {
            return !pred(x, y);
        }
    };

template <class Predicate>
inline binary_negate<Predicate> not2(const Predicate& pred) {
    return binary_negate<Predicate>(pred);
}
