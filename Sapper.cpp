#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

const short ROWS = 6;
const short COLS = 6;
int xp = 0;
int hp = 5;


void generate_mines(char matrix[ROWS][COLS], int& mine1_row, int& mine1_col, int& mine2_row, int& mine2_col) {
    mine1_row = rand() % ROWS;
    mine1_col = rand() % COLS;
    mine2_row = rand() % ROWS;
    mine2_col = rand() % COLS;

    matrix[mine1_row][mine1_col] = 'M';
    matrix[mine2_row][mine2_col] = 'M';
}


bool mine_collision(int p_row, int p_col, int mine1_row, int mine1_col, int mine2_row, int mine2_col, char matrix[ROWS][COLS]) {
    if ((p_row == mine1_row && p_col == mine1_col) || (p_row == mine2_row && p_col == mine2_col)) {
        hp -= 1;
        matrix[mine1_row][mine1_col] = '.';
        matrix[mine2_row][mine2_col] = '.';
        return true;
    }
    return false;
}


void generate_an_apple(char matrix[ROWS][COLS], int& apple_row, int& apple_col) {
    apple_row = rand() % ROWS;
    apple_col = rand() % COLS;
    matrix[apple_row][apple_col] = 'A';
}


void generate_a_fruit(char matrix[ROWS][COLS], int& fruit_row, int& fruit_col) {
    fruit_row = rand() % ROWS;
    fruit_col = rand() % COLS;
    matrix[fruit_row][fruit_col] = 'F';
}


bool check_collision(char matrix[ROWS][COLS], int row, int col) {
    return matrix[row][col] == '#';
}


void generate_walls(char matrix[ROWS][COLS], int& wall1_row, int& wall1_col, int& wall2_row, int& wall2_col) {
    wall1_row = rand() % ROWS;
    wall1_col = rand() % COLS;
    wall2_row = rand() % ROWS;
    wall2_col = rand() % COLS;

    matrix[wall1_row][wall1_col] = '#';
    matrix[wall2_row][wall2_col] = '#';
}


bool check_bounds(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}


template<int row, int col>
void move_player(char direction, int& p_row, int& p_col, char matrix[row][col]) {
    int new_row = p_row;
    int new_col = p_col;

    switch (direction) {
        case 'w':
            new_row--;
            break;
        case 's':
            new_row++;
            break;
        case 'a':
            new_col--;
            break;
        case 'd':
            new_col++;
            break;
        default:
            std::cout << "Invalid move" << std::endl;
            return;
    }

    if (check_bounds(new_row, new_col) && !check_collision(matrix, new_row, new_col)) {
        p_row = new_row;
        p_col = new_col;
    } else {
        std::cout << "Move blocked by wall or out of bounds." << std::endl;
    }
}


template<typename T>
void generate_matrix(T matrix[ROWS][COLS], T initial_value) {
    for (unsigned short i = 0; i < ROWS; i++) {
        for (unsigned short j = 0; j < COLS; j++) {
            matrix[i][j] = initial_value;
        }
    }
}


template<typename T>
void display_matrix(const T matrix[ROWS][COLS], int p_row, int p_col) {
    system("cls");
    for (unsigned short i = 0; i < ROWS; i++) {
        for (unsigned short j = 0; j < COLS; j++) {
            if (i == p_row && j == p_col) {
                std::cout << 'P' << ' ';
            } else {
                std::cout << matrix[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}


void is_collected(char matrix[ROWS][COLS], int player_row, int player_col, int& apple_row, int& apple_col, int& fruit_row, int& fruit_col) {
    if (player_row == apple_row && player_col == apple_col) {
        matrix[apple_row][apple_col] = '.';
        xp += 10;
        generate_an_apple(matrix, apple_row, apple_col);
    }
    else if (player_row == fruit_row && player_col == fruit_col) {
        matrix[fruit_row][fruit_col] = '.';
        xp += 20;
        generate_a_fruit(matrix, fruit_row, fruit_col);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    char matrix[ROWS][COLS];
    generate_matrix(matrix, '.');

    int player_row = 0;
    int player_col = 0;

    int apple_row = 0;
    int apple_col = 0;

    int fruit_row = 0;
    int fruit_col = 0;

    int wall1_row = 0;
    int wall1_col = 0;

    int wall2_row = 0;
    int wall2_col = 0;

    int mine1_row = 0;
    int mine1_col = 0;
    int mine2_row = 0;
    int mine2_col = 0;

    generate_an_apple(matrix, apple_row, apple_col);
    generate_a_fruit(matrix, fruit_row, fruit_col);
    generate_walls(matrix, wall1_row, wall1_col, wall2_row, wall2_col);
    generate_mines(matrix, mine1_row, mine1_col, mine2_row, mine2_col);

    display_matrix(matrix, player_row, player_col);

    while (hp > 0) {
        char move = _getch();
        if (move == 'q') {
            break;
        }

        move_player<ROWS, COLS>(move, player_row, player_col, matrix);


        if (mine_collision(player_row, player_col, mine1_row, mine1_col, mine2_row, mine2_col, matrix)) {
            std::cout << "Mine hit! HP: " << hp << std::endl;
        }


        is_collected(matrix, player_row, player_col, apple_row, apple_col, fruit_row, fruit_col);
        display_matrix(matrix, player_row, player_col);
        std::cout << "Total XP: " << xp << std::endl;
        std::cout << "HP: " << hp << std::endl;
    }

    std::cout << "Game Over!" << std::endl;

    return 0;
}
