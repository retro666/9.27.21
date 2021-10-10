#include <iostream>

int main() {
    unsigned int a, b = 0;
    std::cin >> a;
    for (; a; ++b) {
        for (unsigned int i = a--; i > 1; --i) std::cout << ' ';
        for (unsigned int i = 0; i < b; ++i) std::cout << "**";
        std::cout << "*\x0A";
    }
    return 0;
}