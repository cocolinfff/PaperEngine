#pragma once
#include "script.h"
#include<graphics.h>
class picture :
    public script
{
protected:
    IMAGE pic;
    void (*callback)();
public:
    picture() { type = PICTURE; }
    picture(int, int, int, int, IMAGE);
    picture(int, int, int, int, IMAGE, void (*call)());
    picture(int, int, IMAGE, void (*call)());
    picture(int, int, IMAGE);
    ~picture() {}
    int listen(MOUSEMSG);
    void click() {
        callback();
    }
    void paint();
    void load();
};
