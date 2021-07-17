#pragma once
#include "picture.h"
class character :
    public picture
{
public:
    //int listen(MOUSEMSG m) {
    //    if (m.x > 32 && m.y > 32 && m.x < 1200 - 32 && m.y < 800 - 32)
    //        changePos(m.x - 32, m.y - 32, 1, 1);//简单的监听
    //    return 0;
    //}
    void paint() {
        drawAlpha(&pic, X(), Y());
    }
    void load() {

        getimage(&background, X(), Y(), pic.getwidth() + 1, pic.getheight() + 1);//background是储存的背景图片局部文件，getimage是将屏幕图像储存到background里面
        backX = X(), backY = Y();
    }
    character(int x, int y, IMAGE img, void (*call)()) : picture(x, y, img, call) {}
    ~character() {}
};

