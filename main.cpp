
#include <cstdlib>

#include "total.h"
#include "PlayAndLevel.h"

void palette();

using namespace std;

int main() {

    int ch;
    
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
        Level(lev++);
        while ((ch = getch()) != 'q' && done() == FALSE) //finish 가 끝내는 변수
        {
            Play(ch);
        }
    }
    endwin();
    return 0;

}

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


