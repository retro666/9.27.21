#include <iostream>

int main(){
	unsigned int a;
	std::cin >> a;
	while (a != 4) {
		if (a & 1) {
			if (a >= 0x55555555) {
				std::cerr << "OVF\n";
				return 1;
			}
			std::cout << (a = a * 3 + 1);
		}
		else std::cout << (a >>= 1);
		std::cout << ' ';
	}
	std::cout << "2 1 ...";
	return 0;
}