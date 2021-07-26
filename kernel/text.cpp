#include "text.h"

void text::paint() {
    //putimage(X(), Y(), &background);
    //getimage(&background,X(),Y(),20,Content().length()*5);

    outtextxy(X(), Y(), (LPCTSTR)(Content()).c_str());
}

void text::load() {
    getimage(&background, X(), Y(), 20, Content().length() * 5 + 1);
    backX = X(), backY = Y();
}