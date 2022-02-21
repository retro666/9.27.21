#include "stdafx.h"
#include <corecrt_malloc.h>

template<typename T> class A {
	T* Ar = new T[0];
	size_t s = 0;
public:
	void addElement(T v) {
		register T* b = new T[s + 1];
		memcpy(b, Ar, sizeof(T) * s);
		delete[] Ar;
		Ar = b;
		Ar[s++] = v;
	}
	void outAr() {
		for (size_t i = s; i--;) {
			std::cout << Ar[i];
		}
	}
	T removeElement(size_t i) {
		T b = Ar[i];
		memcpy(&(Ar[i]), &(Ar[i + 1]), (--s - i) * sizeof(T));
		return b;
	}
	void resize(size_t si) {
		if (si * sizeof(T) <= _msize(Ar)) {
			s = si;
		} else {
			si = (size_t)(new T[si]);
			memcpy((T*)si, Ar, s * sizeof(T));
			delete[] Ar;
			Ar = (T*)si;
		}
	}
	T& getElement(size_t i) {
		return Ar[i];
	}
};

int main(){
	A<size_t> a, b;
	a.resize(1);
	a.getElement(0) = 0xDEADBEEF;
	a.resize(10);
	for (char i = 1; i < 10;) {
    a.getElement(i++) = i << 1;
  }
	a.addElement(a.removeElement(5));
	b.addElement(a.getElement(0));
  return b.getElement(2);
}
