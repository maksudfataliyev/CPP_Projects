#include <iostream>
int count(char name[10][10]) {
    int count = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (name[i][j] == '*') {
                count++;
            }
        }
    }
    return count;
}
void generate(char name[10][10]) {
    srand(time(NULL));
    int i = 0;
    while(i<=30) {
        name[rand()%10][rand()%10]='*';
        i = i + 1;
    }
}
int coordinatee_y() {
    int y_choice;
    std::cout <<"Vvdite x"<<std::endl;
    std::cin >> y_choice;
    std::cout<<std::endl;
    return y_choice;
}
int coordinatee_x() {
    int x_choice;
    std::cout <<"Vvedite y"<< std::endl;
    std::cin >> x_choice;
    std::cout<<std::endl;
    return x_choice;
}
void end_or_not(char name[10][10],char name1[10][10], int hod) {
    int coordinate_y = 0;
    int coordinate_x = 0;
    coordinate_y=coordinatee_y();
    coordinate_x=coordinatee_x();
    int counter = count(name);
    if (name[coordinate_x][coordinate_y] == '*') {
        std::cout <<"You lost"<< std::endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cout << name[i][j];
            }
            std::cout <<std::endl;
        }
        return;
    }
    else if (100 - hod == counter) {
        std::cout <<"You won"<< std::endl;
        return;
    }
    else {
        name1[coordinate_x][coordinate_y] = ' ';
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cout << name1[i][j];
            }
            std::cout << std::endl;
        }
        hod = hod + 1;
        end_or_not(name,name1,hod);

    };
}
int main() {
    int a = 0;
    int i = 0;
    char dinar[10][10]={
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };
    char yur[10][10]={
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };
    generate(dinar);
    for(i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            std::cout << yur[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    end_or_not(dinar,yur,a);
    return 0;
    };