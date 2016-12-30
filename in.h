#ifndef __IN_H_
#define __IN_H_
#include <string.h>
#include <iostream>
#include <fstream>
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
    int in_des() {
        std::string line;
        while (getline(if_des_, line)) {
            char origin[1024] = {0};
            strncpy(origin, line.c_str(), line.size());
            T t(origin, line.size(), "\t");
            char buf[1024];
            t.toString(buf, sizeof(buf), '\t');
            printf("%s\n", buf);
        }
        return 0;
    }
    int in_update() {
        std::string line;
        while (getline(if_up_, line)) {
            char origin[1024] = {0};
            strncpy(origin, line.c_str(), line.size());
            T t(origin, line.size(), "\t");
            char buf[1024];
            t.toString(buf, sizeof(buf), '\t');
            printf("%s\n", buf);
        }
        return 0;
    }
private:
    std::ifstream if_des_;
    std::ifstream if_up_;
    char des_[N];
    char update_[N];
};
#endif
