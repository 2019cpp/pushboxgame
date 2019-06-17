//
// Created by 김용환 on 2019-06-17.
//
#include "total.h"
#include "PlayAndLevel.h"

void Play(int input)
{
    bool restart = FALSE;
    chtype up, lf, dw, rg, oup, olf, odw, org;
    up = (mvinch(obj[0].yPos - 1, obj[0].xPos) & A_CHARTEXT);
    lf = (mvinch(obj[0].yPos, obj[0].xPos - 1) & A_CHARTEXT);
    dw = (mvinch(obj[0].yPos + 1, obj[0].xPos) & A_CHARTEXT);
    rg = (mvinch(obj[0].yPos, obj[0].xPos + 1) & A_CHARTEXT);
    oup = (mvinch(obj[0].yPos - 2, obj[0].xPos) & A_CHARTEXT);
    olf = (mvinch(obj[0].yPos, obj[0].xPos - 2) & A_CHARTEXT);
    odw = (mvinch(obj[0].yPos + 2, obj[0].xPos) & A_CHARTEXT);
    org = (mvinch(obj[0].yPos, obj[0].xPos + 2) & A_CHARTEXT);

    for (int o = 0; o <= wbox; o++) { mvaddch(obj[o].yPos, obj[o].xPos, obj[o].ozn); }

    switch (input)
    {
        case 'w':
        case 'W':
            if (up != 35) //벽이 아니라
            {
                step++; //상자의 움직임
                if (up == 64 && (oup == 111 || oup == 120)) //64가 상자에 왔는데 그 다음것이 120 되거나(x빨간색에 오거나) 그냥 움직이면(파란o에 오면)
                {
                    if (oup == 120) count++;

                    obj[0].yPos -= 1;//캐릭터의 움직임
                    for (int o = 1; o <= wbox; o++)
                    {   //캐릭터의 움직임
                        if ((obj[0].yPos == obj[o].yPos) && (obj[0].xPos == obj[o].xPos))
                        {
                            obj[o].yPos -= 1;//상자의 움직임
                            push++;

                        }
                    }
                }
                else if (up != 64) obj[0].yPos -= 1;
                else step--;
            }
            break;
        case 's':
        case 'S':
            if (dw != 35)
            {
                step++;
                if (dw == 64 && (odw == 111 || odw == 120))
                {
                    if (oup == 120) count++;
                    obj[0].yPos += 1;
                    for (int o = 1; o <= wbox; o++)
                    {
                        if ((obj[0].yPos == obj[o].yPos) && (obj[0].xPos == obj[o].xPos))
                        {
                            obj[o].yPos += 1;
                            push++;
                            count++;
                        }
                    }
                }
                else if (dw != 64) obj[0].yPos += 1;
                else step--;
            }
            break;

        case 'a':
        case 'A':
            if (lf != 35)
            {
                step++;
                if (lf == 64 && (olf == 111 || olf == 120))
                {
                    if (oup == 120) count++;
                    obj[0].xPos -= 1;
                    for (int o = 1; o <= wbox; o++)
                    {
                        if ((obj[0].yPos == obj[o].yPos) && (obj[0].xPos == obj[o].xPos))
                        {
                            obj[o].xPos -= 1;
                            push++;
                            count++;
                        }
                    }
                }
                else if (lf != 64) obj[0].xPos -= 1;
                else step--;
            }break;

        case 'd':
        case 'D':
            if (rg != 35)
            {
                step++;
                if (rg == 64 && (org == 111 || org == 120))
                {
                    if (oup == 120) count++;
                    obj[0].xPos += 1;
                    for (int o = 1; o <= wbox; o++)
                    {
                        if ((obj[0].yPos == obj[o].yPos) && (obj[0].xPos == obj[o].xPos))
                        {
                            obj[o].xPos += 1;
                            push++;
                            count++;
                        }
                    }
                }
                else if (rg != 64) obj[0].xPos += 1;
                else step--;
            }break;
        case 'm':
        case 'M':
            step = 0;
            push = 0;
            restart = TRUE;
            if (lev < 5) lev += 1;
            else lev = 0;
            Level(lev);
            break;
        case 'r':
        case 'R':
            step = 0;
            push = 0;
            restart = TRUE;
            Level(lev);
            break;
        default:
            break;
    }
    mvprintw(3, 10, "step: %d, push: %d", step, push);
    if (!restart)
    {
        for (int o = 0; o <= wbox; o++)
        {
            obj[o].ozn = mvinch(obj[o].yPos, obj[o].xPos);
            mvaddch(obj[o].yPos, obj[o].xPos, obj[o].zn | ((o == 0) ? COLOR_PAIR(3) : COLOR_PAIR(5)));
        }
        move(obj[0].yPos, obj[0].xPos);
    }
    else restart = FALSE;

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
