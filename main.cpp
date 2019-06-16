#include <iostream>
#include <cstdlib>
#include "variables.h"



void palette() {
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(2, COLOR_RED, COLOR_BLACK); //목적지
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);//상
    init_pair(6, COLOR_BLUE, COLOR_BLUE);
    init_pair(7, COLOR_BLACK, COLOR_BLACK);
}



bool done(){
    int c = 0;
    for(int i=1;i<=wbox;i++){
        for(int j=1;j<=whole;j++){
            if(obj[i].xPos == end[j].xPos && obj[i].yPos == end[j].yPos)
                c++;
        }
    }
    if(c==wbox){
        lev++;
        step = 0;
        push = 0;
        mvprintw(3, 10, "step: %d, push: %d    ", step, push);

        return TRUE;
    }
    else
        return FALSE;
}

int main() {

    int ch;
    int cnt = 0;
    initscr();
    if (!has_colors())
    {
        endwin();
        printf("Error initialisting colors.n");
        exit(1);
    }

    start_color();
    palette();
    while(lev<6){
        Level(lev);
        while ((ch = getch()) != 'q' && done() == FALSE) //finish 가 끝내는 변수
        {
            Play(ch);
        }
    }
    endwin();
    return 0;

}