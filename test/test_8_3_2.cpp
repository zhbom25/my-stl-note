//
// Created by zhaobo on 2022/2/22.
//
#include <iterator>
using namespace std;

template <typename Container>
class insert_iterator {
protected:
    Container* container;
    typename Container::iterator iter;
public:
    typedef output_iterator_tag     iterator_category;
    typedef void                    value_type;
    typedef void                    difference_type;
    typedef void                    pointer;
    typedef void                    reference;
    insert_iterator(Container& x, typename Container::iterator i) : container(&x), iter(i) {}
    insert_iterator<Container>& operator=(const typename Container::value_type& value) {
        iter = container->insert(iter, value);
        ++iter;
        return *this;
    }
    insert_iterator<Container>& operator*() { return *this; }
    insert_iterator<Container>& operator++() { return *this; }
    insert_iterator<Container>& operator++(int) { return *this; }
};

/*
template <typename Container, typename Iterator>
inline insert_iterator<Container> inserter(Container& x, Iterator i) {
    typedef typename Container::iterator iter;
    return insert_iterator<Container>(x, iter(i));
}
 */
