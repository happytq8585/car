#ifndef __CAR_OP_H__
#define __CAR_OP_H__

#include "cache.h"

class Operations
{
public:
    Operations(const char* des):cache(des){}
    int query_all();
    int query_one(int id);

    int add_one(Info& e);
    int del_one(int id);
    int modify(Info& e);
private:
    Cache<Info> cache;
};

#endif
