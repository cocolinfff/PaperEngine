#pragma once
#include"script.h"
template<class T>
class scriptPool
{
	T** scripts;
	int* alive;
	int max;
	int maxNum;
	int point;
public:
	scriptPool(int);//确定匿名池最大元素数量
	T* each();//调用每一个,所指指针+1，结尾为nullptr（自动跳回起始位）
	void returnZero();//把内置指针拨到起始位
	void addScript(script*);//将一个元素加入匿名池
	void deleteScript(script*);//搜索一个元素并将其删除
	void init(int i);//使一个元素位“活性化”，指唤醒一个空指针，危险操作
};


template<class T>
scriptPool<T>::scriptPool(int num) {
	scripts = new T * [num];
	alive = new int[num];
	for (int i = 0; i < num; i++) alive[i] = 0;
	max = 0; point = 0;
	maxNum = num;
}

template<class T>
T* scriptPool<T>::each() {
	if (point != max && alive[point]) {
		return scripts[point++];
	}
	else if (alive[point] == 0) {
		point++;
		return each();
	}
	else {
		point = 0;
		return nullptr;
	}
}

template<class T>
void scriptPool<T>::returnZero()
{
	point = 0;
}

template<class T>
void scriptPool<T>::addScript(script* s) {
	int sig = 1;
	for (int i = 0; i < max; i++) {
		if (alive[i] == 0) {
			scripts[i] = s;
			alive[i] = 1;
			sig = 0;
		}
	}
	if (sig) {
		scripts[max++] = s;
	}
}

template<class T>
void scriptPool<T>::deleteScript(script* s) {
	for (int i = 0; i < max; i++) {
		if (alive[i]) {
			if (scripts[i] == s) {
				delete script[i];
				alive[i] = 0;
			}
		}
	}
}

template<class T>
void scriptPool<T>::init(int i)
{
	alive[i] = 1;
	max = i + 1;
}

