#include "button.h"
#include"graphics.h"
button::button() :script() {}

button::button(int x, int y, int h, int w, string con, void (*call)()) : script(x, y, h, w, con), callback(call) { type=BUTTON; }

void button::click() {
	callback();
}

int button::listen(MOUSEMSG m) {
	return (m.x > pos_x && m.y > pos_y && m.x < pos_x + pos_h && m.y < pos_y + pos_w)&&(m.uMsg== WM_LBUTTONDOWN);
}

void button::paint() {
    rectangle(X(), Y(), X() + H(), Y() + W());
    outtextxy((3 * X() + H()) / 3, Y() + W() / 4, (LPCTSTR)(Content()).c_str());
}

void button::load() {
    getimage(&background, X(), Y(), H() + 1, W() + 1);
    backX = X(), backY = Y();
}