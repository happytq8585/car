#ifndef __CACHE_H__
#define __CACHE_H__

#include "in.h"
#include <list>
#include <algorithm>

template<class T>
class Cache
{
    class clear
    {
    public:
        void operator()(T*& t) {
            delete t;
        }
    };
    friend class Operations;
    class IF {
    public:
        IF(int id):id_(id){}
        int operator()(T* ptr) {
            return ptr->id == id_;
        }
        int id_;
    };
    Cache(const char* des, const char* up)
    {
        In<T> in(des, up);
        T* ptr = NULL;
        do {
            ptr = in.in_des();
            if (ptr == NULL) {
                break;
            }
            if (is_uniq(ptr)) {
                lst_.push_back(ptr);
                unique_.push_back(ptr->id);
            } else {
                delete ptr;
            }
        } while (ptr != NULL);
        do {
            ptr = in.in_update();
            if (ptr == NULL) {
                break;
            }
            update(ptr);
            delete ptr;
        } while (ptr != NULL);
    }
    int is_uniq(T* ptr);
    int update(T* ptr);
    ~Cache()
    {
        std::for_each(lst_.begin(), lst_.end(), clear());
    }
    std::list<T*> lst_;
    std::list<int> unique_;
};

template<class T>
int Cache<T>::is_uniq(T* ptr)
{
    return find(unique_.begin(), unique_.end(), ptr->id) == unique_.end();
}

template<class T>
int Cache<T>::update(T* ptr)
{
    typename std::list<T*>::iterator it = 
        find_if(lst_.begin(), lst_.end(), IF(ptr->id));
    if (it != lst_.end()) {
        (*it)->update(ptr);
    }
}
#endif
