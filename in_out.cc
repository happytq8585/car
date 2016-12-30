#include "store.h"
#include "in.h"
#include "car.h"
#include "op.h"

static void out()
{
    Store s("des.txt", "update.txt");
    const char* p = "123\t211\tford\t9999\t1970-01-01 03:00:09\tbig_car\t0\t900\t5\t1500\t500\t2000\t999";
    s.store(p);
    s.update(p);
}

static void in()
{
    In<Info> in("des.txt", "update.txt");
//    in.in_des();
//    in.in_update();
}
int main(int argc, char *argv[])
{
    if (argc != 2) {
        Operations op("des.txt", "update.txt");
        op.query_all();
        return 0;
    }
    if (argv[1][0] == '0') {
        out();
    }
    if (argv[1][0] == '1') {
        in();
    }
    return 0;
}
