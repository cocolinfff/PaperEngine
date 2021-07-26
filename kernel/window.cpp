#include "window.h"
#include"script.h"
#include<graphics.h>
#define that list[i]
window::window(int x,int y) {
	height = x, width = y;
	list = new script * [50000];
	call = new int[50000];
	initgraph(x, y);
}

window::~window() {
	closegraph();
}

void window::addScript(script* s) {
	for (int i = 0; i < sNum; i++) {
		if (call[i] == 0) {
			list[i] = s;
			call[i] = 1;
			return;
		}
	}
	list[sNum] = s;
	call[sNum] = 1;
	sNum++;
}

void window::deleteScript(script* s) {
	for (int i = 0; i < sNum; i++) {
		if (s == list[i] && call[i] == 1) {
			call[i] = 0;
			list[i]->repaint();
			delete list[i];
		}
	}
}


int window::checkCollision(script* a, script* b)
{
	if (!((a->X() >= b->X() + b->W()) || (a->X() + a->W() <= b->X()) || (a->Y() >= b->Y() + b->H()) || (a->Y() <= b->Y() - a->H())))
		return 1;
	return 0;
}//没有检查正确性emmm

void window::winMain() {
	while (MouseHit()) {
		MOUSEMSG m = GetMouseMsg();
		for (int i = 0; i < sNum; i++) {
			if (call[i])
				if (that->listen(m)) {
					that->click();
				}
		}
	}
	for (int i = 0; i < sNum; i++) {
		if (that->changed && call[i]) {
			that->repaint();
			that->changed = 1;
		}
	}
	for (int i = 0; i < sNum; i++) {
		if (that->changed && call[i]) {
			that->load();
			that->changed = 1;
		}
	}
	for (int i = 0; i < sNum; i++) {
		if (call[i]) {
			that->paint();
			that->changed = 0;
		}
	}
}
void window::display() {
	for (int i = 0; i < sNum; i++) {
			that->load();
			that->paint();
		} 
}