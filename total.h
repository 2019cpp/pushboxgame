//
// Created by 김용환 on 2019-06-17.
//

#ifndef NN_TOTAL_H
#define NN_TOTAL_H

#include <ncurses.h>

#define N 10


void selectMap(int* , int* , int* , int , int , int );

bool done();


int wbox = 0;
int whole = 0;
int lev = 0;
int step = 0;
int push = 0;
int count = 0;

class Object
{
public:
    int xPos;
    int yPos;
    unsigned char zn;
    chtype ozn;// ozn 이 전거? 그 전거? 한칸옮기니까 목적
};


Object obj[N] = {};
Object end[N] = {};



#endif //NN_TOTAL_H
