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
    int id; //car id
    char number[N]; //car number
    char company[N]; //made in which company
    struct {
        time_t t; //when buy this car in seconds from 1970-1-1 00:00:00
        char str[N]; //transfer seconds into strings
    } time;
    struct {
        char name[N];
        int  type; //0=big, 1=small, 2=truck
    } type;
    int distance;
    int distance_price;
    int maintain_price;
    int road_price;
    int total_price;
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
