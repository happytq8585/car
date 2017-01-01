#ifndef __STORE_H__
#define __STORE_H__
#include <fstream>

#include "car.h"

class Store
{
    static const int N = 64;
public:
    Store(const char* des);
    ~Store();
    int store(const char* line);
    int operator()(Info* ptr);
private:
    std::ofstream of_des_;
    char des_[N];
};
#endif
