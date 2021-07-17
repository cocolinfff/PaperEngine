#pragma once
#include "script.h"
#include"graphics.h"
class button :
    public script{
private:
    void (*callback)();
public:
    button();
    button(int, int, int, int, string, void (*call)());
    button(void (*call)()) :callback(call) {}
    ~button(){}
    int listen(MOUSEMSG m);
    void click();
    void paint();
    void load();
};

