//1.


#include <iostream>


void transposeMatrix(int row, int col) {
    int original[row][col]= {};

    std::cout << "original matrix:\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            original[i][j] = rand() % 10;
            std::cout << original[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int new_row = col;
    int new_col = row;


    int new_matrix[new_row][new_col] = {};

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            new_matrix[j][i] = original[i][j];
        }
    }


    std::cout << "new matrix:\n";
    for (int i = 0; i < new_row; ++i) {
        for (int j = 0; j < new_col; ++j) {
            std::cout << new_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int main() {
    int row, col;

    std::cout << "row: ";
    std::cin >> row;
    std::cout << "col: ";
    std::cin >> col;

    transposeMatrix(row, col);

    return 0;
}


//2.

#include <iostream>


void rotateAndPrintMatrix(int n) {
    int matrix[n][n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            std::swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int mainn() {
    int n;
    std::cin >> n;
    rotateAndPrintMatrix(n);


    return 0;
}


