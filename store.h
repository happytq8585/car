#ifndef __STORE_H__
#define __STORE_H__
#include <fstream>

class Store
{
    static const int N = 64;
public:
    Store(const char* des, const char* update);
    ~Store();
    int store(const char* line);
    int update(const char* line);
private:
    std::ofstream of_des_;
    std::ofstream of_up_;
    char des_[N];
    char update_[N];
};
#endif
