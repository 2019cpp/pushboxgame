//
// Created by 김용환 on 2019-06-16.
//
#include "variables.h"

void Level(int n)
{
    mvprintw(1, 8, "LEVEL %d", lev);
    mvprintw(2, 1, "R-restart, M-map ,WASD-move");
    mvprintw(3, 10, "step: %d, push: %d", step, push);
    int x = 0, y = 0, h = 1, w = 1, map;
    wbox = 0;
    whole = 0;
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            selectMap(&h, &w, &map, y, x, n);
            switch (map)
            {
                case 0: mvaddch(y + 4, x + 10, 'o' | COLOR_PAIR(4)); break;
                case 1: mvaddch(y + 4, x + 10, '#' | COLOR_PAIR(1)); break;
                case 2:
                    whole += 1;
                    end[whole].ozn = mvinch(y + 4, x + 10);
                    end[whole].yPos = y + 4;
                    end[whole].xPos = x + 10;
                    end[whole].zn = 'x';
                    mvaddch(end[whole].yPos, end[whole].xPos, end[whole].zn | COLOR_PAIR(2));
                    break;
                case 4:
                    mvaddch(y + 4, x + 10, 'o' | COLOR_PAIR(4));
                    wbox += 1;
                    obj[wbox].ozn = mvinch(y + 4, x + 10);
                    obj[wbox].yPos = y + 4;
                    obj[wbox].xPos = x + 10;
                    obj[wbox].zn = '@';
                    mvaddch(obj[wbox].yPos, obj[wbox].xPos, obj[wbox].zn | COLOR_PAIR(5));
                    break;
                case 5:
                    mvaddch(y + 4, x + 10, 'o' | COLOR_PAIR(4));
                    obj[0].ozn = mvinch(y + 4, x + 10);
                    obj[0].yPos = y + 4;
                    obj[0].xPos = x + 10;
                    obj[0].zn = 'P';
                    mvaddch(obj[0].yPos, obj[0].xPos, obj[0].zn | COLOR_PAIR(3));
                    break;
                case 6:mvaddch(y + 4, x + 10, '#' | COLOR_PAIR(6)); break;
                case 7:mvaddch(y + 4, x + 10, '#' | COLOR_PAIR(7)); break;
            }
        }
    }
    move(obj[0].yPos, obj[0].xPos);

}
