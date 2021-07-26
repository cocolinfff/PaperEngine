#pragma once
#include <string>
#include<graphics.h>
#include"function.h"

using std::string;

enum {
	NONE,BUTTON,TEXT,PICTURE
};
class MOUSEMSG;
class script
{
protected:
	int pos_x, pos_y;//postion
	int pos_h, pos_w;//size
	std::string content;//text
	
public:
	friend MOUSEMSG;
	int type;
	bool changed;
	IMAGE background; int backX, backY;

	script();
	script(int,int,int,int);
	script(int,int,int,int,string);
	script(string);
	~script();
	
	void changePos(int,int,int,int);//changePos
	void changeContent(string);//changeContent


	virtual int listen(MOUSEMSG) = 0;//listen if clicked;
	virtual void click() = 0;//if click , function

	int X() { return pos_x; }
	int Y() { return pos_y; }
	int H() { return pos_h; }
	int W() { return pos_w; }
	string Content() { return content; }

	virtual void paint()=0;//paint on the window
	virtual void load()=0;//load the background
	void repaint();//paint the loads
};



