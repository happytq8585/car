#include "store.h"
#include <string.h>
#include <iostream>

using namespace std;

Store::Store(const char* des):
    of_des_(des, ios::app)
{
    strncpy(des_, des, sizeof(des_));
}

Store::~Store()
{
    of_des_.close();
}
int Store::store(const char* line)
{
    of_des_ << line << endl;
    return 0;
}

int Store::operator()(Info* ptr)
{
    if (ptr->valid == 0) {
        return -1;
    }
    char buf[1024] = {0};
    ptr->toString(buf, sizeof(buf), '\t');
    return store(buf);
}
