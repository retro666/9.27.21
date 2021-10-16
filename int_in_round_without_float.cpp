#include <iostream>

inline unsigned int sqrti(long long a) {
	unsigned int r = 0;
	for (unsigned int i = 0x80000000; i; i >>= 1) {
		if ((long long)i * i <= a - ((long long)r * i << 1)) {
			a += (unsigned long long)r * r;
			a -= ((unsigned long long)(r += i) * r);
		}
	}
	return r;
}

int main(){
	int a;
	std::cin >> a;
	if (!a) {
		std::cout << 1;
		return 0;
	}
	unsigned long long b = a;
	for (unsigned int i = a - 1; i; i--) b += sqrti(((unsigned long long)a - i) * (a + i));
	std::cout << (b << 2) + 1;
	return 0;
}