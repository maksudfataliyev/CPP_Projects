#include <iostream>

void add_row_at(short& size, int**& arr, short row) {
    srand(time(NULL));
    int** new_arr = new int*[size + 1];

    for (int i = 0; i < row; i++) {
        new_arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            new_arr[i][j] = arr[i][j];
        }
    }

    new_arr[row] = new int[size];
    for (int i = 0; i < size; i++) {
        new_arr[row][i] = rand() % 10;
    }

    for (int i = row + 1; i < size + 1; i++) {
        new_arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            new_arr[i][j] = arr[i - 1][j];
        }
    }

    size++;

    for (int i = 0; i < size - 1; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = new_arr;
}

void add_column_at(short& size, int**& arr, short col) {
    srand(time(NULL));
    int** new_arr = new int*[size];

    for (int i = 0; i < size; i++) {
        new_arr[i] = new int[size + 1];
        for (int j = 0, k = 0; j < size; j++) {
            if (j == col) {
                new_arr[i][k++] = rand() % 10;
            }
            new_arr[i][k++] = arr[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    size++;

    arr = new_arr;
}

void remove_row_at(short& size, int**& arr, short row) {
    int** new_arr = new int*[size - 1];

    for (int i = 0, k = 0; i < size; i++) {
        if (i == row) continue;
        new_arr[k] = new int[size];
        for (int j = 0; j < size; j++) {
            new_arr[k][j] = arr[i][j];
        }
        k++;
    }

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    size--;

    arr = new_arr;
}

void remove_column_at(short& size, int**& arr, short col) {
    int** new_arr = new int*[size];

    for (int i = 0; i < size; i++) {
        new_arr[i] = new int[size - 1];
        for (int j = 0, k = 0; j < size; j++) {
            if (j == col) continue;
            new_arr[i][k++] = arr[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    size--;

    arr = new_arr;
}

void print_array(int** arr, short rows, short cols) {
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    short size = 5;
    short row;
    short col;
    short choice;
    srand(time(NULL));

    int** arr = new int*[size];
    for (int a = 0; a < size; a++) {
        arr[a] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    short currentCols = size;
    print_array(arr, size, currentCols);

    while (true) {
        std::cout << "add row(0) add col(1) remove row(2) remove col(3)" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 0:
 std::cout << "Enter the row" << std::endl;
                std::cin >> row;
                add_row_at(size, arr, row);
                currentCols = size;
                print_array(arr, size, currentCols - 1);
                break;
            case 1:
                std::cout << "Enter the col" << std::endl;
                std::cin >> col;
                add_column_at(size, arr, col);
                currentCols = size;
                print_array(arr, size, currentCols);
                break;
            case 2:
                std::cout << "Enter the row" << std::endl;
                std::cin >> row;
                remove_row_at(size, arr, row);
                currentCols = size;
                print_array(arr, size, currentCols);
                break;
            case 3:
                std::cout << "Enter the col" << std::endl;
                std::cin >> col;
                remove_column_at(size, arr, col);
                currentCols = size - 1;
                print_array(arr, size, currentCols);
                break;
            default:
                continue;
        }
    }

    return 0;
}