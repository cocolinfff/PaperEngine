#include "script.h"
#include "window.h"
script::script() {}

script::script(int x, int y, int h, int w) {
	pos_x = x, pos_y = y, pos_h = h, pos_w = w;
	type = NONE;
	changed = 1;
}

script::script(int x, int y, int h, int w, string con) {
	pos_x = x, pos_y = y, pos_h = h, pos_w = w;
	content = con;
	type = NONE;
	changed = 1;
}

script::script(string con) {
	content = con;
	type = NONE;
	changed = 1;
}

script::~script() {}


void script::changeContent(string con) {
	content = con;
	changed = 1;
}

void script::changePos(int x, int y, int h, int w) {
	pos_x = x, pos_y = y, pos_h = h, pos_w = w;
	changed = 1;
}

void script::repaint() {
	putimage(backX, backY, &background);
}