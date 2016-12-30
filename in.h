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
    In(const char* des, const char* update):
        if_des_(des, std::ios::app), if_up_(update, std::ios::app)
    {
        strncpy(des_, des, sizeof(des_));
        strncpy(update_, update, sizeof(update_));
    }
    ~In()
    {
        if_des_.close();
        if_up_.close();
    }
    T* in_des();
    T* in_update();
private:
    std::ifstream if_des_;
    std::ifstream if_up_;
    char des_[N];
    char update_[N];
};
template<class T>
T* In<T>::in_des()
{
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
    return NULL;
}
template<class T>
T* In<T>::in_update()
{
    std::string line;
    if (!getline(if_up_, line)) {
        return NULL;
    }
    char origin[1024] = {0};
    strncpy(origin, line.c_str(), line.size());
    T t(origin, line.size(), "\t");
    if (t.valid == 1) {
        T* pt = new T(t);
        return pt;
    }
    return NULL;
}
#endif
