#include <iostream>

inline unsigned int sqrti(unsigned long long a) {
	unsigned int r = 0;
	for (unsigned int i = 0x80000000; i; i >>= 1) {
		if ((long long)i * i <= (long long)a - ((long long)r * i << 1)) {
			a += (unsigned long long)r * r;
			a -= ((unsigned long long)(r += i) * r);
		}
	}
	return r;
}

inline unsigned long long answer(unsigned int a) {
	if (!a) return 1;
	unsigned long long b = a;
	for (unsigned int i = a - 1; i; i--) b += sqrti(((unsigned long long)a - i) * (a + i));
	return (b << 2) + 1;
}

int main() {
	unsigned int a;
	std::cin >> a;
	std::cout << answer(a);
	return 0;
}
