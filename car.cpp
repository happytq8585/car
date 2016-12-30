#include "car.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Info::Info(char* buf, int size, const char* delim)
{
    char old[2048] = {0};
    strncpy(old, buf, sizeof(old));
    valid = 0;
    int i;
    char *p = strtok(buf, delim);
    if (p == NULL) {
        goto err;
    }
    id = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    snprintf(number, sizeof(number), "%s", p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    snprintf(company, sizeof(company), "%s", p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    time.t = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    snprintf(time.str, sizeof(time.str), "%s", p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    snprintf(type.name, sizeof(type.name), "%s", p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    type.type = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    distance = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    distance_price = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    maintain_price = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    road_price = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    total_price = atoi(p);
    p = strtok(NULL, delim);
    if (p == NULL) {
        goto err;
    }
    extra_info.number_unit = atoi(p);
    valid = 1;
err:
    snprintf(buf, sizeof(buf), "该字段解析有误! line=%s", old);
}
int Info::toString(char *buf, int size, char c)
{
    if (valid == 0) {
        return -1;
    }
    int n = 0;
    n += snprintf(buf+n, size-n, "%d%c", id, c);
    n += snprintf(buf+n, size-n, "%s%c", number, c);
    n += snprintf(buf+n, size-n, "%s%c", company, c);
    n += snprintf(buf+n, size-n, "%d%c%s%c", time.t, c, time.str, c);
    n += snprintf(buf+n, size-n, "%s%c%d%c", type.name, c, type.type, c);
    n += snprintf(buf+n, size-n, "%d%c%d%c%d%c", distance, c, distance_price, c, maintain_price, c);
    n += snprintf(buf+n, size-n, "%d%c%d%c%d%c", road_price, c, total_price, c, extra_info.number_unit, c);
    buf[n] = '\0';
    return n;
}
