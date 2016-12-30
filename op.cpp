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
