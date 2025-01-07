//Задание 1

#include <iostream>

char lowercase[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char uppercase[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int length(char* arr) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    std::cout << length << std::endl;
    return length;
}


int printUpper(char* arr) {
    int l = length(arr);
    for (short i = 0; i < l; i++) {
        for (short j = 0; j < 26; j++) {
            if (arr[i] == lowercase[j]) {
                arr[i] = uppercase[j];
                break;
            }
        }
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

typedef int (*function)(char*);

void funcfromarr(int index, char* arr, function operation[]) {
    if (index == 0 || index == 1) {
        operation[index](arr);
    } else {
        std::cout << "Error!" << std::endl;
    }
}

int main() {
    function operation[] = {length, printUpper};


    char array[] = {'a', 'b', 'q', '\0'};

    int index;

    std::cout << "(0 - length, 1 - printUpper): ";
    std::cin >> index;

    funcfromarr(index, array, operation);

    return 0;
}

//Задание 2

#include <iostream>

int length(int* arr) {
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    return len;
}


void vosrastaniye(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void ubivaniye(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

typedef void (*func)(int*, int);


void functionn(int index, int* arr, func operation[]) {
    if (index == 0 || index == 1) {
        operation[index](arr, length(arr));
    } else {
        std::cout << "Error" << std::endl;
    }
}

int mainn() {
    int arr[] = {5, 2, 9, 1, 5, 6, '\0'};

    func operations[] = {vosrastaniye, ubivaniye};

    int index;
    std::cout << "0(++)1(--)";
    std::cin >> index;

    functionn(index, arr, operations);

    for (int i = 0; i < length(arr); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//Задание 3

#include <iostream>


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0)
        {return a / b;};
    std::cout << "/0" << std::endl;
    return 0;
}


typedef int (*operationFunc)(int, int);

int funct(int index, operationFunc operation[], int a, int b) {
    if (index == 0 or index == 1 or index == 2 or index == 3) {
         int result = operation[index](a, b);
         return result;
    }
    else {
        std::cout << "error" << std::endl;
    }
}
int mainnn() {
    operationFunc operations[] = {multiply, divide,add, subtract,};
    int a;
    std::cin >> a;
    int b;
    std::cin >> b;
    int index;
    std::cout << "multiply(0), divide(1),add(2), subtract(3)"<<std::endl;
    std::cin >> index;
    std::cout<<funct(index, operations, a, b);

    return 0;
}


