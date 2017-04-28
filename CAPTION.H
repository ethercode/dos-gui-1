#ifndef _CAPTION_
#define _CAPTION_

#include "window.h"

#define LEFTALIGNED 1
#define CENTERED 2
#define RIGHTALIGNED 3

class TCaption:public TWindow
{
public:

    void    predefine(int num);
    void    drawFlat();
    void    drawUp();
    void    drawDown();
    void    reset();
    void    setFlat(int flatness);
    void    setInterval(int intervalTime);
    void    setEnabled(int enabledFlag);
    void    checkForEvents();


            TCaption(TObject* parentObject);
            ~TCaption();
    void    setCaption(char* newCaption);
    void    paint();
    void    setJustify(int justification);

private:
    int     justify;
    char*   caption;
};

#endif