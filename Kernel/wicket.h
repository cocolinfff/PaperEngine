#pragma once
#include"script.h"
class wicket
{
private:
	int width;
	int height;
	struct node{
		script* data;
		node* next;
		node() :data(nullptr),next(nullptr){}
	};
	node* root;
public:
};

