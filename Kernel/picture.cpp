#include "picture.h"
picture::picture(int x, int y, int h, int w, IMAGE buf) :script(x, y, h, w), pic(buf) { type = PICTURE; }
picture::picture(int x, int y, IMAGE buf,void (*call)()) : script(x, y, 0, 0), pic(buf),callback(call) {
	type = PICTURE; 
	changePos(x, y, pic.getwidth(), pic.getheight());
}

int picture::listen(MOUSEMSG m) {
	return (m.x > pos_x && m.y > pos_y && m.x < pos_x + pos_h && m.y < pos_y + pos_w) && (m.uMsg == WM_LBUTTONDOWN);
}

void picture::paint() {
	putimage(X(), Y(), pic.getwidth(),pic.getheight(),&pic,0,0);
}

void picture::load() {
    getimage(&background, X(), Y(), background.getwidth()+1,background.getheight()+1);
    backX = X(), backY = Y();
}