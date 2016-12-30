#include "car.h"
#include <stdio.h>
#include <string.h>

Info::Info(char buf[], int size, const char* delim)
{
    valid = 0;
    int i;
    char *p = strtok(buf, "\t");
    if (p == NULL) {
        return;
    }
    id = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    snprintf(number, sizeof(number), "%s", p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    snprintf(company, sizeof(company), "%s", p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    time.t = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    snprintf(t.str, sizeof(t.str), "%s", p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    snprintf(type.name, sizeof(type.name), "%s", p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    type.type = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    distance = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    distance_price = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    maintain_price = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    road_price = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    total_price = atoi(p);
    p = strtok(NULL, delim)
    if (p == NULL) {
        return;
    }
    extra_info.number_unit = atoi(p);
    valid = 1;
}
int Info::toString(char buf[], int size)
{
    if (valid == 0) {
        return -1;
    }
    int n = 0;
    n += snprintf(buf+n, size-n, "%d\t", id);
    n += snprintf(buf+n, size-n, "%s\t", number);
    n += snprintf(buf+n, size-n, "%s\t", company);
    n += snprintf(buf+n, size-n, "%d\t%s\t", time.t, time.str);
    n += snprintf(buf+n, size-n, "%s\t%d\t", type.name, type.type);
    n += snprintf(buf+n, size-n, "%d\t%d\t%d\t", distance, distance_price, maintain_price);
    n += snprintf(buf+n, size-n, "%d\t%d\t%d\t", road_price, total_price, extra_info.number_unit);
}
