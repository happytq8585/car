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
    Cache(const char* des, const char* update)
    {
        In<T> in(des, update);
        in.in_des(lst_);
        in.in_update(lst_);
    }
    ~Cache()
    {
        std::for_each(lst_.begin(), lst_.end(), clear());
    }
    std::list<T*> lst_;
};

#endif
