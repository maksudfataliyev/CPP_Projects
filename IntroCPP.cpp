#include <iostream>

int main() {
    int a;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    std::cin >> a;
    a1 = (a / 100000) + 2;
    a2 = ((a / 10000) % 10) + 2;
    a3 = ((a / 1000) % 10) + 2;
    a4 = ((a / 100) % 10) + 2;
    a5 = ((a / 10) % 10) + 2;
    a6 = (a % 10) + 2;
    std::cout << a1<< a2<< a3<< a4<< a5 << a6 << std::endl;
}
