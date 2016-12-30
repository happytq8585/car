#include "store.h"
#include <string.h>
#include <iostream>

using namespace std;

Store::Store(const char* des, const char* update):
    of_des_(des, ios::app), of_up_(update, ios::app)
{
    strncpy(des_, des, sizeof(des_));
    strncpy(update_, update, sizeof(update_));
}

Store::~Store()
{
    of_des_.close();
    of_up_.close();
}
int Store::store(const char* line)
{
    of_des_ << line << endl;
    return 0;
}

int Store::update(const char* line)
{
    of_up_ << line << endl;
    return 0;
}
