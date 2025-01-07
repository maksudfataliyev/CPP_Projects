#include <iostream>

int main() {
    int S_index;
    S_index = 8;
    int E_index;
    E_index = 11;
    char maze[] = {
        '#', '#', '#', '#', '#', '#', '\n',
        '#', 'S', '#', 'E', ' ', '#', '\n',
        '#', ' ', '#', '#', ' ', '#', '\n',
        '#', ' ', '#', ' ', ' ', '#', '\n',
        '#', ' ', ' ', ' ', ' ', '#', '\n',
        '#', '#', '#', '#', '#', '#', '\n'
    };

    while (true) {
        if (maze[E_index + 1] == maze[S_index]) {
            std::cout << "You have finished the maze" << std::endl;
            break;
        }
        if (maze[S_index + 1] == ' ') {
            maze[S_index] = '*';
            S_index = S_index + 1;
            maze[S_index] = 'S';
            std::cout << maze << std::endl;
            continue;
        }
        else if (maze[S_index - 7] == ' ') {
            maze[S_index] = '*';
            S_index = S_index - 7;
            maze[S_index] = 'S';
            std::cout << maze << std::endl;
            continue;
        }
        else if (maze[S_index + 7] == ' ') {
            maze[S_index] = '*';
            S_index = S_index + 7;
            maze[S_index] = 'S';
            std::cout<<maze<<std::endl;
            continue;
        }
        else if (maze[S_index - 1] == ' ') {
            maze[S_index] = '*';
            S_index = S_index - 1;
            maze[S_index] = 'S';
            std::cout << maze << std::endl;
            continue;
        }
    }
    return 0;
}