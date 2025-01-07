#include <iostream>

int* insert(int*& arr, int index, int& size, int number) {
    size = size + 1;
    int* new_arr = new int[size];

    for (int i = 0; i < index; i++) {
        new_arr[i] = arr[i];
    }

    new_arr[index] = number;

    for (int i = index + 1; i < size; i++) {
        new_arr[i] = arr[i - 1];
    }

    delete[] arr;

    return new_arr;
}

int* pop(int*& arr, int index, int& size) {
    size = size - 1;
    int* new_arr = new int[size];

    for (int i = 0; i < index; i++) {
        new_arr[i] = arr[i];
    }

    for (int i = index; i < size; i++) {
        new_arr[i] = arr[i + 1];
    }

    delete[] arr;

    return new_arr;
}

void clear(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int main() {
    int size = 10;
    int index;
    int number;
    srand(time(NULL));

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    bool a = true;
    while (a) {
        int choice;
        std::cout << "choice :(1 - insert), (2 - pop), (3 - clear and end)" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter the number: " << std::endl;
                std::cin >> number;
                std::cout << "Enter the index: " << std::endl;
                std::cin >> index;

                while (index < 0 || index > size) {
                    std::cout << "Invalid index! Enter the correct index: " << std::endl;
                    std::cin >> index;
                }
                arr = insert(arr, index, size, number);
                break;
            }
            case 2: {
                std::cout << "Enter the index to remove: " << std::endl;
                std::cin >> index;

                while (index < 0 || index >= size) {
                    std::cout << "Invalid index! Enter the correct index: " << std::endl;
                    std::cin >> index;
                }

                arr = pop(arr, index, size);
                break;
            }
            case 3: {
                clear(arr);
                a = false;
                break;
            }
            default: {
                std::cout << "Invalid choice! Try again." << std::endl;
            }
        }

        if (a) {
            std::cout << "Updated array: ";
            for (int i = 0; i < size; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }


    return 0;
}