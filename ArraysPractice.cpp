#include <iostream>

int main() {
    char dinar[] = {'+','x'};
    int number;
    const int row = 5,col = 5;
    int counter;
    int i = 0;
    int c;
    int row_choice;
    int col_choice;
    char symbol;
    int del_or_not;
    char yur[row][col] = {
    };
    char yuriy[row][col] = {};
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << yuriy[i][j];
        }
        std::cout << std::endl;
    }
    srand(time(NULL));
    number = rand()%2;
    std::cout << "Nado narisovat: "<<dinar[number] << std::endl;
    if (dinar[number] == '+') {
        counter = (row/2);
        while (i <= counter * 2) {
            yur[i][counter] = '+';
            yur[counter][i] = '+';
            i = i + 1;
        }
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < row; ++k) {
                std::cout << yur[k][j];
            }
            std::cout << std::endl;
        }
    }
    else {
        counter = row - 1;
        c = counter;
        while (i <= counter) {
            yur[i][i] = 'x';
            i = i + 1;
        }
        i = 0;
        while (i <= c) {
            yur[i][counter] = 'x';
            i = i + 1;
            counter = counter - 1;
        }
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < row; ++k) {
                std::cout << yur[k][j];
            }
            std::cout << std::endl;

        }
    }
    if (dinar[number] == '+') {
        symbol = dinar[number];
    }
    else {
        symbol = 'x';
    }
    while (yuriy != yur) {
        std::cout << "enter the row"<<std::endl;
        std::cin>>row_choice;
        std::cout<<std::endl;
        std::cout << "enter the col"<<std::endl;
        std::cin>>col_choice;
        std::cout<<std::endl;
        yuriy[row_choice][col_choice] = symbol;
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < row; ++k) {
                std::cout << yuriy[k][j];
            }
            std::cout << std::endl;
        }
        std::cout <<"do you want to delete anything?(0=no,1=yes)" <<std::endl;
        std::cin>>del_or_not;
        while (del_or_not == 1) {
            std::cout << "enter the row"<<std::endl;
            std::cin>>row_choice;
            std::cout<<std::endl;
            std::cout << "enter the col"<<std::endl;
            std::cin>>col_choice;
            std::cout<<std::endl;
            yuriy[row_choice][col_choice] = ' ';
            for (int j = 0; j < col; ++j) {
                for (int k = 0; k < row; ++k) {
                    std::cout << yuriy[k][j];
                }
                std::cout << std::endl;
            }
            std::cout<<"more?"<<std::endl;
            std::cin>>del_or_not;
        }




    }



}