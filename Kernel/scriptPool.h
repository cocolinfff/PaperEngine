#pragma once
#include"script.h"
template<class T>
class scriptPool
{
	T** scripts;
	int* alive;
	int max;
	int point;
public:
	scriptPool(int);//默认1000吧
	T *each();//调用每一个，结尾为nullptr
	void addScript(script*);
	void deleteScript(script*);
};

