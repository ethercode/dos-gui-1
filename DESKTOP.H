#ifndef _DESKTOP_
#define _DESKTOP_

#include "window.h"

class TDesktop:public TWindow
{
public:

            TDesktop();
            ~TDesktop();
    void    paint(void);
    void    drawFlat();
    void    drawUp();
    void    drawDown();
    void    predefine(int num);
    void    setCaption(char* newCaption);
    void    reset(void);
    void    setFlat(int flatness);
    void    killApp();
    int     mustTerminate();

private:
    int     fillStyle;
    int     fillColour;
    int     terminate;
};

#endif
