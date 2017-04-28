#include "mouse.h"

TMouse::TMouse()
{
    visible = 0;
    asm
    {
        mov ax,0x0007
        mov cx,0;
        mov dx,639;
        int 0x33;
        mov ax,0x0008
        mov cx,0;
        mov dx,479;
        int 0x33;
    }
    setMousePosition(319, 239);
    leftDown = 0;
    rightDown = 0;
    show();
}

TMouse::~TMouse()
{
    hide(0, 0, 639, 479);
}


void TMouse::show()
{
    if (!visible)
    {
        visible = 1;
        asm
        {
            mov ax,0x0001;
            int 0x33;
        }
    }
}

int TMouse::checkInside(int x1, int y1, int x2, int y2)
{
    if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void TMouse::hide(int x1, int y1, int x2, int y2)
{
    if (visible)
    {
        update();
        if ((x > x1) && (x < x2) && (y > y1) && (y < y2))
        {
            visible = 0;
            asm
            {
                mov ax,0x0002;
                int 0x33;
            }
        }
    }
}

void TMouse::hide()
{
    if (visible)
    {
        {
            visible = 0;
            asm
            {
                mov ax,0x0002;
                int 0x33;
            }
        }
    }
}

void TMouse::setMousePosition(int x, int y)
{
    asm
    {
        mov ax,0x0004
        mov cx,x;
        mov dx,y;
        int 0x33;
    }
}

void TMouse::update()
{
    unsigned int xPos,yPos,bState;
    asm
    {
        mov ax,0x0003
        int 0x33
        mov bState,bx
        mov xPos,cx
        mov yPos,dx
    }
    if (bState == 0)
    {
        oldLeftDown = leftDown;
        leftDown = 0;
        oldRightDown = rightDown;
        rightDown = 0;
    }
    if (bState == 1)
    {
        oldLeftDown = leftDown;
        leftDown = 1;
    }
    if (bState == 2)
    {
        oldRightDown = rightDown;
        rightDown = 1;
    }
    if (bState == 3)
    {
        oldLeftDown = leftDown;
        leftDown = 1;
        oldRightDown = rightDown;
        rightDown = 1;
    }
    x = xPos;
    y = yPos;
}








