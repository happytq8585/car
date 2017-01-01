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
    n += snprintf(buf+n, size-n, "%ld%c%s%c", time.t, c, time.str, c);
    n += snprintf(buf+n, size-n, "%s%c%d%c", type.name, c, type.type, c);
    n += snprintf(buf+n, size-n, "%d%c%d%c%d%c", distance, c, distance_price, c, maintain_price, c);
    n += snprintf(buf+n, size-n, "%d%c%d%c%d%c", road_price, c, total_price, c, extra_info.number_unit, c);
    buf[n] = '\0';
    return n;
}

void Info::display(char *buf, int size)
{
    char s[1024] = {0};
    int n = 0, N = sizeof(s);
    n += snprintf(s+n, N-n, "汽车ID=%d\n", id);
    n += snprintf(s+n, N-n, "汽车车牌号=%s\n", number);
    n += snprintf(s+n, N-n, "汽车生产公司=%s\n", company);
    n += snprintf(s+n, N-n, "汽车购买时间=%s\n", time.str);
    n += snprintf(s+n, N-n, "汽车类型=%s\n", type.name);
    n += snprintf(s+n, N-n, "总公里数=%d\n", distance);
    n += snprintf(s+n, N-n, "耗油量/公里=%d\n", distance_price);
    n += snprintf(s+n, N-n, "基本维护费=%d\n", maintain_price);
    n += snprintf(s+n, N-n, "累计总费用=%d\n", total_price);
    if (type.type == 0) {
        n += snprintf(s+n, N-n, "最大载客数=%d\n", extra_info.number_capacity);
    } else if (type.type == 1) {
        n += snprintf(s+n, N-n, "小轿车车厢数=%d\n", extra_info.number_unit);
    } else if (type.type == 2) {
        n += snprintf(s+n, N-n, "卡车载重重量=%d\n", extra_info.total_weight);
    } else {
        n = snprintf(s, N, "车子类型不正确[大客车, 卡车, 小轿车]\n");
        valid = 0;
    }
    s[n] = '\0';
    if (buf != NULL && size != 0) {
        strncpy(buf, s, n);
    }
    printf("%s", s);
}
