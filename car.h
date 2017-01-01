#ifndef __CAR_H__
#define __CAR_H__

#include <time.h>

struct Info
{
    Info(char*, int size, const char* delim);
    int toString(char*, int bufSize, char c);
    void display(char* buf=NULL, int size=0);
    int update(const Info* ptr) { *this = *ptr; }
    static const int N = 64;
    int valid; // 0=invalid  1=invalid
    int id; //car id    1
    char number[N]; //car number    2
    char company[N]; //made in which company   3
    struct {
        time_t t; //when buy this car in seconds from 1970-1-1 00:00:00   4
        char str[N]; //transfer seconds into strings   5
    } time;
    struct {
        char name[N];  //  6
        int  type; //0=big, 1=small, 2=truck     7
    } type;
    int distance;  // 8
    int distance_price; // 9
    int maintain_price; // 10
    int road_price; // 11
    int total_price; // 12
    union {
        int number_capacity; //for big car
        int number_unit; //for small car
        int total_weight; //for truck
    } extra_info;
};
class Car
{
};

#endif
