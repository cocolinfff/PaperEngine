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
	scriptPool(int);//Ĭ��1000��
	T *each();//����ÿһ������βΪnullptr
	void addScript(script*);
	void deleteScript(script*);
};

