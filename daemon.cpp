#include "store.h"
#include "in.h"
#include "car.h"
#include "op.h"

static void out()
{
    Store s("des.txt");
    const char* p = "123\t211\tford\t9999\t1970-01-01 03:00:09\tbig_car\t0\t900\t5\t1500\t500\t2000\t999";
    s.store(p);
}

static int query_one(Operations& op, int id)
{
    if (op.query_one(id) < 0) {
        printf("this car id does not exist!\n");
    }
}
static int query_all(Operations& op)
{
    op.query_all();
}
static int del(Operations& op, int id)
{
    int r = op.del_one(id);
    if (r < 0) {
        printf("this car id does not exist!\n");
        return -1;
    }
    printf("delete car id=%d successfully!\n", id);
    return 0;
}
static int add_or_modify(Operations& op, int type=0)
{//type == 0 add;  type == 1 modify
    char tok[13][32] = {0};
    printf("input car id:\n");
    scanf("%s", tok[0]);
    printf("input car number:\n");
    scanf("%s", tok[1]);
    printf("input company:\n");
    scanf("%s", tok[2]);
    printf("input time:\n");
    strcpy(tok[3], "000");
    scanf("%s", tok[4]);
    printf("input type: big small or truck:\n");
    scanf("%s", tok[5]);
    if (strcmp(tok[5], "big") == 0) {
        strcpy(tok[6], "0");
    } else if (strcmp(tok[5], "small") == 0) {
        strcpy(tok[6], "1");
    } else if (strcmp(tok[5], "truck") == 0) {
        strcpy(tok[6], "2");
    } else {
        strcpy(tok[6], "3");
    }
    printf("input distance:\n");
    scanf("%s", tok[7]);
    printf("input distance_price:\n");
    scanf("%s", tok[8]);
    printf("input maintain_price:\n");
    scanf("%s", tok[9]);
    printf("input road_price:\n");
    scanf("%s", tok[10]);
    printf("input total_price:\n");
    scanf("%s", tok[11]);
    printf("input extra_info:\n");
    scanf("%s", tok[12]);
    char buf[1024] = {0};
    int i = 0, n = 0;
    for (; i < 12; ++i) {
        n += snprintf(buf+n, sizeof(buf)-n, "%s%c", tok[i], '\t');
    }
    n += snprintf(buf+n, sizeof(buf)-n, "%s", tok[12]);
    Info info(buf, n, "\t");
    if (info.valid == 0) {
        printf("input is invalid!\n");
        return -1;
    }
    if (info.valid == 1) {
        int r = 0;
        if (type == 0) {
            r = op.add_one(info);
            if (r < 0) {
                printf("this car id already exists!\n");
                return -1;
            }
            else
            {
                printf("add successfully!\n");
            }
            return 0;
        }
        else if (type == 1) {
            r = op.modify(info);
            if (r < 0) {
                printf("this car id does not exist!\n");
                return -1;
            }
            else
            {
                printf("modify successfully!\n");
            }
            return 0;
        }
    }
    return 0;
}

static int start_daemon()
{
    Operations op("des.txt");
    int id;
    while (1) {
        printf("input selection: 1=add 2=del 3=modify 4=query_one 5=queyr_all other=exit\n");
        int a;
        if (scanf("%d", &a) < 1) {
            return 0;
        }
        switch(a)
        {
            case 1:
                add_or_modify(op, 0);
                break;
            case 2:
                printf("input car id:");
                scanf("%d", &id);
                del(op, id);
                break;
            case 3:
                add_or_modify(op, 1);
                break;
            case 4:
                printf("input car id:");
                scanf("%d", &id);
                query_one(op, id);
                break;
            case 5:
                query_all(op);
                break;
            default:
                return 0;
        }
    }
    return 0;
}
int main(int argc, char *argv[])
{
    start_daemon();
    return 0;
}
