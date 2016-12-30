#ifndef __CAR_OP_H__
#define __CAR_OP_H__

#include "cache.h"

class Operations
{
public:
    Operations(const char* des, const char* update):cache(des, update){}
    int query_all();
    int query_one();

    int add_one();
    int del_one();
    int edit_one();
private:
    Cache<Info> cache;
};

#endif
