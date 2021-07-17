#pragma once
#include "script.h"
#include<graphics.h>
class text :
    public script
{
public:
    text() { type = TEXT; }
    text(int x, int y, string con) :script(x, y, 0, 0,con) { type = TEXT; }
    ~text() {}
    int listen(MOUSEMSG m) { return 0; };
    void click() {}
    void paint();
    void load();
};

