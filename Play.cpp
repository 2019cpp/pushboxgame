#include "variables.h"

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