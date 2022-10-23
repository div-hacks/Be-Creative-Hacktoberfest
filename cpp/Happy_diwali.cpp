#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
 
int main()
{
    int gd, gm;
    int x, y;
    int i, j, kk;
 
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm,"c:\\tc\\bgi");
 
    setcolor(WHITE);
    line(0, 400, 640, 400);
    rectangle(300, 330, 340, 400);
    rectangle(310, 320, 330, 330);
    setcolor(4);
    line(319, 280, 319, 398);
    line(320, 280, 320, 398);
    rectangle(320, 280, 330, 300);
    outtextxy(340, 280, "PRESS ANY KEY TO IGNITE THE ROCKET");
    getch();
 
    for (j=400; j<640; j++)
    {
        cleardevice();
        setcolor(WHITE);
        line(0, j, 640, j);
        rectangle(300, j-70, 340, j);
        rectangle(310, j-80, 330, j-70);
 
        setcolor(RED);
        line(319, 280, 319, 400);
        line(320, 280, 320, 400);
        rectangle(320, 280, 330, 300);
        setcolor(YELLOW);
        circle(325,300,2);
 
        delay(5);
    }
 
    for (i=400; i>340; i--)
    {
        cleardevice();
        setcolor(RED);
        line(319, i, 319, i-120);
        line(320, i, 320, i-120);
        rectangle(320, i-120, 330, i-100);
 
        setcolor(YELLOW);
        circle(325, i-100, 2);
        delay(25);
    }
 
    cleardevice();
    kk = 0;
    for (j=100; j<350; j++)
    {
        if (j%20==0)
        {
            setcolor(kk);
            kk=kk+3;
            delay(50);
        }
        ellipse(320, 30, 0, 360, j+100, j+0);
    }
 
    for (j=100; j<350; j++)
    {
        if (j%20==0)
        {
            setcolor(BLACK);
            delay(2);
        }
        ellipse(320, 30, 0, 360, j+100, j+0);
    }
 
    cleardevice();
    i = 0;
    while (!kbhit())
    {
        setcolor(i++);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
        outtextxy(70, 150, "GfG wishes u happy diwali!");
        delay(90);
    }
 
    getch();
    return 0;
}
