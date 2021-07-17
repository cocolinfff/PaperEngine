#pragma once
#include"script.h"
class window
{
private:
	int height,  width, sNum;
	script** list;
	int *call;
public:
	window(int,int);
	~window();
	void addScript(script* s);
	void deleteScript(script* s);
	void display();//initialize
	void winMain();//listen to callback
	int checkCollision(script*, script*);
};

