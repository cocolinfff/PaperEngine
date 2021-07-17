#include "scriptPool.h"
template<class T>
scriptPool<T>::scriptPool(int num) {
	scripts = new T * [num];
	alive = new int[num];
	for (int i = 0; i < num; i++) alive[i] = 0;
	max = 0; point = 0;
}

template<class T>
T* scriptPool<T>::each() {
	if (point != max) {
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
void scriptPool<T>::addScript(script* s) {
	int sig = 1;
	for (int i = 0; i < max; i++) {
		if (alive[i]==0) {
			scripts[i] = s; 
			alive[i] = 1;
			sig = 0;
		}
	}
	if (sig) {
		scripts[max++]=s;
	}
}
void deleteScript();