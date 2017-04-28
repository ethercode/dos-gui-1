#ifndef _FORM_
#define _FORM_

#include "window.h"

class TForm:public TWindow
{
public:

            TForm();
            TForm(TObject* root);
            ~TForm();

    void    predefine(int num);
    void    paint();
    void    setCaption(char* newCaption);
    void    drawFlat();
    void    drawUp();
    void    drawDown();
    void    checkForEvents();
    void    childCheckForEvents();
    void    drawChangeBox(int x1, int y1, int x2, int y2);
    void    setFlat(int flatness);
    void    reset(void);

private:

    int     captionColour;
    int     captionTextColour;
    int     foregroundColour;
    int     dark3d;
    int     light3d;
    int     hasCaption;
    int     canMove;
    char*   caption;
};

#endif
