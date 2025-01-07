#include <iostream>

int main() {
    srand(time(NULL));
    int col=3, row=3;
    int top_left;
    int top_right;
    int bottom_left;
    int bottom_right;
    int dinar[row][col] = {
        {},
        {},
        {}
    };
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            dinar[i][j] = rand()%10;
            std::cout << dinar[i][j];
        }
        std::cout << std::endl;
    }
    top_left = dinar[0][0];
    top_right = dinar[0][col-1];
    bottom_left = dinar[row-1][0];
    bottom_right = dinar[row-1][col-1];
    dinar[0][0] = bottom_right;
    dinar[0][col-1] = bottom_left;
    dinar[row-1][col-1] = top_left;
    dinar[row-1][col] = top_right;
    std::cout<<std::endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            std::cout << dinar[i][j];
        }
        std::cout << std::endl;
    }
}

#include <iostream>

int mainn() {
    srand(time(NULL));
    int row = 3, col = 3;
    int matrix[row][col];


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 10;
        }
    }


    std::cout<< std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    int shift;
    std::cout << "-2;2";
    std::cin >> shift;


    if (shift == 1) {
        for (int i = 0; i < row; i++) {
            int temp = matrix[i][col - 1];
            for (int j = col - 1; j > 0; j--) {
                matrix[i][j] = matrix[i][j - 1];
            }
            matrix[i][0] = temp;
        }
    } else if (shift == 2) {
        for (int i = 0; i < row; i++) {

            int temp1 = matrix[i][col - 1];
            int temp2 = matrix[i][col - 2];
            for (int j = col - 1; j > 1; j--) {
                matrix[i][j] = matrix[i][j - 2];
            }
            matrix[i][1] = temp1;
            matrix[i][0] = temp2;
        }
    } else if (shift == -1) {
        for (int i = 0; i < row; i++) {
            int temp = matrix[i][0];
            for (int j = 0; j < col - 1; j++) {
                matrix[i][j] = matrix[i][j + 1];
            }
            matrix[i][col - 1] = temp;
        }
    } else if (shift == -2) {
        for (int i = 0; i < row; i++) {
            int temp1 = matrix[i][0];
            int temp2 = matrix[i][1];
            for (int j = 0; j < col - 2; j++) {
                matrix[i][j] = matrix[i][j + 2];
            }
            matrix[i][col - 2] = temp1;
            matrix[i][col - 1] = temp2;
        }
    }

    std::cout<< std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}