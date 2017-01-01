#ifndef __CACHE_H__
#define __CACHE_H__

#include "in.h"
#include "store.h"
#include <string.h>
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
    Cache(const char* des)
    {
        strncpy(name_, des, sizeof(name_));
        In<T> in(des);
        T* ptr = NULL;
        while (1) {
            int flag = 0;
            ptr = in.in_des(flag);
            if (flag == 0) {
                continue;
            }
            if (ptr == NULL) {
                break;
            }
            if (is_uniq(ptr)) {
                lst_.push_back(ptr);
                unique_.push_back(ptr->id);
            } else {
                delete ptr;
            }
        }
    }
    int is_uniq(T* ptr);
    int update(T* ptr);
    int add(T* ptr);
    int del(int id);
    T* query_one(int id);
    ~Cache()
    {
        typename std::list<T*>::iterator it;
        Store s(name_);
        for (it = lst_.begin(); it != lst_.end(); ++it) {
            char buf[1024] = {0};
            (*it)->toString(buf, sizeof(buf), '\t');
            s.store(buf);
        }
        std::for_each(lst_.begin(), lst_.end(), clear());
    }
    std::list<T*> lst_;
    std::list<int> unique_;
    char name_[128];
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
        return 0;
    }
    return -1;
}
template<class T>
int Cache<T>::add(T* ptr)
{
    if (!is_uniq(ptr)) {
        return -1;
    }
    lst_.push_back(new T(*ptr));
    unique_.push_back(ptr->id);
    return 0;
}
template<class T>
int Cache<T>::del(int id)
{
    typename std::list<T*>::iterator it = 
        find_if(lst_.begin(), lst_.end(), IF(id));
    if (it != lst_.end()) {
        lst_.erase(it);
        return 0;
    }
    return -1;
}
template<class T>
T* Cache<T>::query_one(int id)
{
    typename std::list<T*>::iterator it = 
        find_if(lst_.begin(), lst_.end(), IF(id));
    if (it != lst_.end()) {
        return *it;
    }
    return NULL;
}
#endif
