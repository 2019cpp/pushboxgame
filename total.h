//
// Created by 김용환 on 2019-06-17.
//

#ifndef NN_TOTAL_H
#define NN_TOTAL_H

#include <ncurses.h>

#define N 10


void selectMap(int* , int* , int* , int , int , int );

bool done();


 static int wbox = 0;
 static int whole = 0;
 static int lev = 0;
 static int step = 0;
 static int push = 0;
 static int count = 0;

class Object
{
public:
    int xPos;
    int yPos;
    unsigned char zn;
    chtype ozn;// ozn 이 전거? 그 전거? 한칸옮기니까 목적
};


static Object obj[N] = {};
static Object end[N] = {};



#endif //NN_TOTAL_H
