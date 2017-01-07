#include "op.h"
#include <stdio.h>
#include <list>
#include <algorithm>

using namespace std;

static void display(Info*& ptr)
{
    ptr->display();
    /*
    char buf[1024];
    ptr->toString(buf, sizeof(buf), '\t');
    printf("%s\n", buf);
    */
}

int Operations::query_all()
{
    list<Info*>& lst = cache.lst_;
    for_each(lst.begin(), lst.end(), display);
    return 0;
}
int Operations::query_one(int id)
{
    Info* ptr = cache.query_one(id);
    if (ptr == NULL) {
        return -1;
    }
    ptr->display();
    return 0;
}

int Operations::add_one(Info& e)
{
    return cache.add(&e);
}

int Operations::del_one(int id)
{
    return cache.del(id);
}

int Operations::modify(Info& e)
{
    if (!e.valid) {
        return -1;
    }
    return cache.update(&e);
}
