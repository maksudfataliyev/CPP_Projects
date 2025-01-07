//2)

#include <iostream>


int main() {
    int N = 7;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            if (j < N - i || j >= N + i)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }


    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * N; j++) {
            if (j < N - i || j >= N + i)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

//1)

#include <iostream>

int mainn() {
    int N = 5;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if ((i == 2 && j == 3) || (i == 3 && j >= 2 && j < 4))
                std::cout << "  ";
            else
                std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}
