#ifndef __IN_H_
#define __IN_H_
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include "car.h"

template<class T>
class In
{
    static const int N = 64;
public:
    In(const char* des):
        if_des_(des, std::ios::app)
    {
        strncpy(des_, des, sizeof(des_));
    }
    ~In()
    {
        if_des_.close();
    }
    T* in_des(int& flag);
private:
    std::ifstream if_des_;
    char des_[N];
};
template<class T>
T* In<T>::in_des(int& flag)
{
    flag = 1;
    std::string line;
    if (!getline(if_des_, line)) {
        return NULL;
    }
    char origin[1024] = {0};
    strncpy(origin, line.c_str(), line.size());
    T t(origin, line.size(), "\t");
    if (t.valid == 1) {
        T* pt = new T(t);
        return pt;
    }
    flag = 0;
    return NULL;
}
#endif
