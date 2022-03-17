#include <iostream>
//#include "config10.h"
//#include "test_1_9_2.h"
//#include "test_1_9_4.h"
#include "test_1_9_6.h"
#include <vector>
#include "my_alloc.h"
#include "zballoc.h"

using namespace std;

/*
template <typename T>
class vector {
public:
    typedef T value_type;
    typedef value_type* iterator;

    template<typename I>
    void insert(iterator position, I first, I last) {
        std::cout << "insert()" << std::endl;
    }
};
*/

enum {__ALIGN = 8};
enum {__MAX_BYTES = 128};
enum {__NFREELISTS = __MAX_BYTES/__ALIGN};

static size_t ROUND_UP(size_t bytes);

//int main(int argc, char** argv)
//{
    /*
    int ia[5] = {0,1,2,3,4};
    vector<int> x;
    vector<int>::iterator ite;
    x.insert(ite, ia, ia+5);
    std::cout<<"Hello, World!"<<std::endl;
    */
    //stack<int> x;
    /*
    int ia[6] = {0,1,2,3,4,5};
    vector<int> iv(ia, ia+6);
    for_each(iv.begin(), iv.end(), print<int>());
    */
    /*
    INT I(5);
    cout << I++;
    cout << ++I;
    cout << I--;
    cout << --I;
    cout << *I;
     */
    /*
    string* str = new string ("hello");
    vector<int>* vec = new vector<int>();
    Plus<int> plusObj;
    Minus<int> minusObj;
    cout << plusObj(10,5) << endl;
    cout << minusObj(11,4) << endl;
    cout << Plus<int>()(12,7) << endl;
    cout << Minus<int>()(13,2) << endl;
    */
    /*
    vector<int, MyAlloc<int>> *vec = new vector<int, MyAlloc<int>>();
    vec->push_back(1);
    vec->push_back(2);
    for (auto iter = vec->cbegin(); iter != vec->cend(); ++iter) {
        cout << "iter val : " << *iter << endl;
    }
    vector<int, JJ::allocator<int>> *mvec = new vector<int, JJ::allocator<int>>();
    mvec->push_back(3);
    mvec->push_back(4);
    mvec->push_back(5);
    for (auto iter = mvec->cbegin(); iter != mvec->cend(); ++iter) {
        cout << "mvec val : " << *iter << endl;
    }
    */
    /*
    char* ptr = (char*)malloc(10);
    cout << "size ptr : " << sizeof(ptr) << endl;
    cout << "size *ptr : " << sizeof(*ptr) << endl;
    ptr = "helloxxxxxxxssss";
    cout << "*ptr : " << (*(ptr+4)) << endl;
    int n = 10;
    int extra = 4;
    char *result = (char *)malloc(n + extra);
    *(size_t *)result = n;
    cout << "result type: " << typeid((*result)).name() << endl;
    cout << "*result : " << sizeof(result) << endl;
    //return result + extra;
     */
    /*
    vector<int> test_vec = {312,129,128,127,64,63,35,32,31,17,16,15,5,4,3,2,1};
    for (auto iter = test_vec.begin(); iter != test_vec.end(); ++iter) {
        cout << "old val : " << *iter << " ; alloc size : " << ROUND_UP(*iter) << endl;
    }
     */
    union obj {
        union obj * free_list_link;
        char client_data[1];    /* The client sees this.        */
    };
    /*
    char* a = (char*)malloc(200);
    obj* p = (obj*)a;
    cout << "sizeof *p : " << sizeof(*p) << endl;
    cout << "sizeof p: " << sizeof(p) << endl;
    //p->client_data[] = "axxxdddsssddd";
    cout << "val : " << p->client_data << endl;
     */

   // return 0;
//}

static size_t ROUND_UP(size_t bytes) {
    return (((bytes) + __ALIGN-1) & ~(__ALIGN - 1));
    //return ~(__ALIGN - 1);
}

/*
15      = 0000 0000 0000 1111
        + 0000 0000 0000 0111
        = 0000 0000 0001 0110

                if (x<8) {
                    ret = 8;
                } else {
                    (x + 7) / 8 * 8
                }

0111
1000 -1 = 0000 0000 0000 0111
         ~1111 1111 1111 1000
*/