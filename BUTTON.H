#ifndef _BUTTON_
#define _BUTTON_

#include "window.h"

#define FLAT 1
#define UP 2
#define DOWN 3

class TButton:public TWindow
{
public:

            TButton();
            TButton(TObject* parentObject);
            ~TButton();

    void    paint(void);
    void    drawDown();
    void    drawFlat();
    void    drawUp();
    void    reset(void);
    void    checkForEvents();
    void    childCheckForEvents();
    void    onClick();
    void    setCaption(char* newCaption);
    void    setFlat(int flatness);

private:

    int     captionColour;
    int     captionTextColour;
    int     foregroundColour;
    int     dark3d;
    int     light3d;
    int     flat;
    int     mayClick;
    char*   caption;
};

#endif