#include <stdio.h>
#include <curses.h>


#define FILAK 6

#define KONTRAKOAK 2

void mugimendua(int *y,int x,int tekla);


int main()
{
    //puntuazioa


    int punt;
    punt=0;
    short nibelak;
    nibelak=1;
    //avioia

    char plane1[FILAK]={'|','-','|',' ',' '};
    char plane2[FILAK]={'}','=','=','0','>'};
    char plane3[FILAK]={'|','-','|',' ',' '};

    //kontrako avioiak

    char kontra1[KONTRAKOAK]={'O'};

    char kontra2[KONTRAKOAK]={'+'};

    char kontra3[KONTRAKOAK]={'D'};

    char kontra4[KONTRAKOAK]={'A'};

    char kontra5[KONTRAKOAK]={'U'};

    char kontra6[KONTRAKOAK]={'@'};

    char kontra7[KONTRAKOAK]={'<'};

    char borratu[KONTRAKOAK]={' '};


    //explosioa
    char aexplosioa1[FILAK]={' ',' ',' ',' ',' '};
    char aexplosioa2[FILAK]={' ',' ','*',' ',' '};
    char aexplosioa3[FILAK]={' ',' ','*',' ',' '};
    char aexplosioa4[FILAK]={' ',' ',' ',' ',' '};

    char bexplosioa1[FILAK]={' ',' ',' ',' ',' '};
    char bexplosioa2[FILAK]={' ','*','*',' ',' '};
    char bexplosioa3[FILAK]={' ','*','*',' ',' '};
    char bexplosioa4[FILAK]={' ',' ',' ',' ',' '};

    char explosioa1[FILAK]={'*',' ',' ',' ','*'};
    char explosioa2[FILAK]={' ','*','*','*',' '};
    char explosioa3[FILAK]={' ','*','*','*',' '};
    char explosioa4[FILAK]={'*',' ',' ',' ','*'};



    //avioiaren hasierako pozizioak

    int ypos;
    int xpos;
    menu:
        punt=0;
        nibelak=1;

    ypos=9;
    xpos=4;

    //kontrakoek nundik ertetzen duten

    int ykont1;
    int xkont1;

    int ykont2;
    int xkont2;

    int ykont3;
    int xkont3;

    int ykont4;
    int xkont4;

    int ykont5;
    int xkont5;

    int ykont6;
    int xkont6;

    int ykont7;
    int xkont7;

    ykont1=2;
    xkont1=40;


    ykont2=9;
    xkont2=47;

    ykont3=12;
    xkont3=65;

    ykont4=16;
    xkont4=55;

    ykont5=18;
    xkont5=47;

    ykont6=5;
    xkont6=32;

    ykont7=14;
    xkont7=60;


    int tekla;
    int menua;


    initscr();
    curs_set(0);

    erase();
    move(10,20);printw("-JOLASTEKO SAKATU -> TEKLA");
    move(11,20);printw("-IRTETZEKO SAKATU <- TEKLA");
    refresh();
    keypad(stdscr, 1);
    nodelay(stdscr, 0);

    noecho();

    menua=getch();
    switch(menua)
    {
    case KEY_RIGHT:
        {
            goto hasiera;
            break;

        }
        case KEY_LEFT:
        {
            return 0;
            break;

        }
    default:
        {
            goto menu;
            break;

        }


}
refresh();

   hasiera:

       if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(0,0);printw("PUNTUAZIOA: %d-NIBELA:%hd",punt,nibelak);
        attroff(COLOR_PAIR(1));
        }



    refresh();

    if (xkont1%2==0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ypos,xpos);printw(plane1);
        move(ypos+1,xpos);printw(plane2);
        move(ypos+2,xpos);printw(plane3);
        attroff(COLOR_PAIR(1));
        }

    }
    else
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ypos,xpos);printw(plane1);
        move(ypos+1,xpos);printw(plane2);
        move(ypos+2,xpos);printw(plane3);
        attroff(COLOR_PAIR(0));
        }

    }



    nodelay(stdscr, 1);

    noecho();

    tekla = getch();

    mugimendua(&ypos,xpos,tekla);

    erase();
    //lehenengo kontrakoa
    if(xkont1!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont1,xkont1);printw(kontra1);
        attroff(COLOR_PAIR(1));
        }

        if((xkont1!=(xpos+5)) || (ykont1!=(ypos+1))&&(ykont1!=(ypos+2))&&ykont1!=ypos)

            xkont1--;
        else
        {

            move(ykont1,xkont1);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont1=(rand()/2000)+8;
        if(ykont1==0)
            ykont1++;
        xkont1=47;
        punt=punt+5;

    }


    //bigarrenengo kontrakoa

    if(xkont2!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont2,xkont2);printw(kontra2);
        attroff(COLOR_PAIR(1));
        }
        if((xkont2!=(xpos+5)) || (ykont2!=(ypos+1))&&(ykont2!=(ypos+2))&&ykont2!=ypos)

            xkont2--;
        else
        {
            move(ykont2,xkont2);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont2=rand()/2000;
        if(ykont2==0)
            ykont2++;
        xkont2=47;
        punt=punt+5;

    }
        //hirugarrenengo kontrakoa
    if(xkont3!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont3,xkont3);printw(kontra3);
        attroff(COLOR_PAIR(1));
        }
        if((xkont3!=(xpos+5)) || (ykont3!=(ypos+1))&&(ykont3!=(ypos+2))&&ykont3!=ypos)

            xkont3--;
        else
        {
            move(ykont3,xkont3);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont3=rand()%5+6;
        xkont3=65;
        if(ykont3==0)
            ykont3+2;
        punt=punt+5;

    }
    //laugarrenengo kontrakoa

    if(xkont4!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont4,xkont4);printw(kontra4);
        attroff(COLOR_PAIR(1));
        }
        if((xkont4!=(xpos+5)) || (ykont4!=(ypos+1))&&(ykont4!=(ypos+2))&&ykont4!=ypos)

            xkont4--;
        else
        {
            move(ykont4,xkont4);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont4=rand()%8+6;
        if(ykont4==0)
            ykont4++;
        xkont4=55;
        punt=punt+5;

    }
        //bostgarrenengo kontrakoa
    if(xkont5!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont5,xkont5);printw(kontra5);
        attroff(COLOR_PAIR(1));
        }
        if((xkont5!=(xpos+5)) || (ykont5!=(ypos+1))&&(ykont5!=(ypos+2))&&ykont5!=ypos)

            xkont5--;
        else
        {
            move(ykont5,xkont5);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont5=rand()%3+7;
        if(ykont5==0)
            ykont5++;
        xkont5=47;
        punt=punt+5;

    }
    //seigarrenengo kontrakoa

    if(xkont6!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont6,xkont6);printw(kontra6);
        attroff(COLOR_PAIR(1));
        }
        if((xkont6!=(xpos+5)) || (ykont6!=(ypos+1))&&(ykont6!=(ypos+2))&&ykont6!=ypos)

            xkont6--;
        else
        {
            move(ykont6,xkont6);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont6=(rand()%4)*7;
        if(ykont6==0)
            ykont6++;
        xkont6=32;
        punt=punt+5;

    }
    //zazpigarrenengo kontrakoa
        if(xkont7!=0)
    {
        if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(ykont7,xkont7);printw(kontra7);
        attroff(COLOR_PAIR(1));
        }
        if((xkont7!=(xpos+5)) || (ykont7!=(ypos+1))&&(ykont7!=(ypos+2))&&ykont7!=ypos)

            xkont7--;
        else
        {
            move(ykont7,xkont7);printw(borratu);

            move(ypos,xpos);printw(aexplosioa1);
            move(ypos+1,xpos);printw(aexplosioa2);
            move(ypos+2,xpos);printw(aexplosioa3);
            move(ypos+3,xpos);printw(aexplosioa4);

            refresh();

            usleep(150000);


            move(ypos,xpos);printw(bexplosioa1);
            move(ypos+1,xpos);printw(bexplosioa2);
            move(ypos+2,xpos);printw(bexplosioa3);
            move(ypos+3,xpos);printw(bexplosioa4);

            refresh();

            usleep(150000);

            move(ypos,xpos);printw(explosioa1);
            move(ypos+1,xpos);printw(explosioa2);
            move(ypos+2,xpos);printw(explosioa3);
            move(ypos+3,xpos);printw(explosioa4);
            refresh();

            usleep(900000);

            goto bukaera;


        }
    }
    else
    {
        ykont7=rand()%70+10;
        if(ykont7==0)
            ykont7++;
        xkont7=60;
        punt=punt+5;

    }




    if(punt==140)
    {
        xpos=xpos++;
        nibelak=2;
    }


    if(punt==280)
    {
        xpos=xpos+5;
        nibelak=3;

    }

    if (punt<500)
    usleep(40000);
    else
    {
        usleep(30000);
        nibelak=4;

    }



    goto hasiera;

    bukaera:
         if (has_colors()) {
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(10,20);printw("ASTEROIDEAREN KONTRA TXOKE EGIN DUZU!!");
        move(11,20);printw("PUNTUAZIOA:   %d PUNTU  NIBELA: %hd",punt,nibelak);
        attroff(COLOR_PAIR(1));
        }

        refresh();
        nodelay(stdscr, 0);
        getchar();


        goto menu;


    endwin();
    return 0;
}
void mugimendua(int *y,int x,int tekla)
{

    switch(tekla)
    {
        case KEY_UP:
            {
                if((*y)>1)

                    (*y)--;
                break;
            }

        case KEY_DOWN:
            {
                if((*y)<=20)

                    (*y)++;

                break;
            }
    }

}



