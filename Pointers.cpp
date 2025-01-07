//ПЕРВОЕ ЗАДАНИЕ

#include <iostream>

int main() {
    int row;
    int col;
    srand(time(NULL));
    std::cin >> row ;
    std::cout<<std::endl;
    std::cin >> col;
    std::cout<<std::endl;
    int matrix[row][col];
    int matrix1[row][col];
    int matrix2[row][col];
    int* ptr;
    int* ptr1;
    int result;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
                matrix[i][j] = rand() % 10;
                std::cout<<matrix[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix1[i][j] = rand() % 10;
            std::cout<<matrix1[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ptr = &matrix[i][j];
            ptr1 = &matrix1[i][j];
            result = *ptr + *ptr1;
            matrix2[i][j] = result;
            std::cout<<matrix2[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
    return 0;
}

//ВТОРОЕ ЗАДАНИЕ

#include <iostream>

int mainn() {
    int row;
    int col;
    std::cin >> row;
    std::cin >> col;
    int matrix[row][col];
    int* ptr;
    int min_number = 10;
    int min_row = 0;
    int min_col = 0;
    srand(time(NULL));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 10;
            ptr = &matrix[i][j];
            std::cout << *ptr;
            if (*ptr <= min_number) {
                min_number = *ptr;
                min_row = i;
                min_col = j;
            }
            else {
                min_number = min_number;
            }
        }
        std::cout << std::endl;
    }
    std::cout <<"min number"<<min_number<<std::endl;
    std::cout <<"row"<<min_row<<std::endl;
    std::cout <<"col"<<min_col<<std::endl;
    return 0;
}

//ТРЕТЬЕ

#include <iostream>

int mainnn() {
    int n;
    std::cin >> n;
    srand(time(NULL));
    int A[n][n];


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 10;
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int main_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;


    for (int i = 0; i < n; ++i) {
        main_diagonal_sum += A[i][i];
        secondary_diagonal_sum += A[i][n - 1 - i];
    }


    if (n % 2 != 0) {
        main_diagonal_sum -= A[n / 2][n / 2];
    }
    int total_sum = main_diagonal_sum + secondary_diagonal_sum;
    if (n % 2 == 1) {
        total_sum = total_sum+ A[n / 2][n / 2];
    }
    std::cout << total_sum << std::endl;

    return 0;
}

