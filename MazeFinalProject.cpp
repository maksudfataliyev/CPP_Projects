#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>

const int WIDTH = 21;
const int HEIGHT = 21;

class Maze {
public:
    Maze(int width, int height) : width(width), height(height) {
        maze.resize(height, std::vector<char>(width, '#'));
        srand(static_cast<unsigned int>(time(0)));
        generateMaze(1, 1);
        setStartAndEnd();
        while (!isPathAvailable()) {
            maze = std::vector<std::vector<char>>(height, std::vector<char>(width, '#'));
            generateMaze(1, 1);
            setStartAndEnd();
        }
    }

    void display() {
        for (const auto& row : maze) {
            for (const auto& cell : row) {
                std::cout << cell;
            }
            std::cout << std::endl;
        }
    }

    char& at(int x, int y) {
        return maze[y][x];
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width, height;
    std::vector<std::vector<char>> maze;
    int a, b;
    void generateMaze(int x, int y) {
        std::vector<std::pair<int, int>> directions = {
            {2, 0}, {-2, 0}, {0, 2}, {0, -2}
        };

        std::random_shuffle(directions.begin(), directions.end());

        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (isInBounds(nx, ny) && maze[ny][nx] == '#') {
                maze[y + dir.second / 2][x + dir.first / 2] = ' ';
                maze[ny][nx] = ' ';
                generateMaze(nx, ny);
            }
        }
    }

    void setStartAndEnd() {
        maze[1][1] = 'S';
        int endX = 2 * (rand() % (width / 2 - 1)) + 1;
        int endY = height - 2;
        maze[endY][endX] = 'E';
        a = endY;
        b = endX;
    }

    bool isInBounds(int x, int y) {
        return x > 0 && x < width && y > 0 && y < height;
    }

    bool isPathAvailable() {
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (maze[y][x] == 'S') {
                    q.push({x, y});
                    visited[y][x] = true;
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (maze[y][x] == 'E') {
                return true;
            }

            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (isInBounds(nx, ny) && !visited[ny][nx] && maze[ny][nx] != '#') {
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

public:
    int returna() {
        return a;
    }

    int returnb() {
        return b;
    }
};

class Item {
private:
    int _x, _y;

public:
    Item(Maze& maze) {
        _x = rand() % (maze.getWidth() / 2) * 2 + 1;
        _y = rand() % (maze.getHeight() / 2) * 2 + 1;
        while (maze.at(_x, _y) != ' ') {
            _x = rand() % (maze.getWidth() / 2) * 2 + 1;
            _y = rand() % (maze.getHeight() / 2) * 2 + 1;
        }
        maze.at(_x, _y) = 'I';
    }

    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }

    ~Item() {
    }
};

class Player {
private:
    int _x, _y, _hp;

public:
    Player(Maze& maze) : _x(1), _y(1), _hp(3) {
        maze.at(_x, _y) = 'P';
    }

    int getHp() const {
        return _hp;
    }

    void minusHp() {
        _hp--;
    }

    void move(Maze& maze, Item*& item) {
        char input;
        std::cin >> input;

        if (input == 'w' && _y > 0 && maze.at(_x, _y - 1) != '#') {
            maze.at(_x, _y) = ' ';
            _y--;
        }
        else if (input == 's' && _y < maze.getHeight() - 1 && maze.at(_x, _y + 1) != '#') {
            maze.at(_x, _y) = ' ';
            _y++;
        }
        else if (input == 'a' && _x > 0 && maze.at(_x - 1, _y) != '#') {
            maze.at(_x, _y) = ' ';
            _x--;
        }
        else if (input == 'd' && _x < maze.getWidth() - 1 && maze.at(_x + 1, _y) != '#') {
            maze.at(_x, _y) = ' ';
            _x++;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
            return;
        }

        if (item != nullptr && _x == item->getX() && _y == item->getY()) {
            delete item;
            item = nullptr;
            _hp++;
        }

        maze.at(_x, _y) = 'P';
    }

    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }
};

class Enemy {
private:
    int _x, _y, _speed;
    int steps, direction;

public:
    Enemy(Maze& maze) : _x(5), _y(5), _speed(rand() % 3 + 1), steps(0), direction(0) {
        while (maze.at(_x, _y) == 'E' || maze.at(_x, _y) == 'P') {
            _x = rand() % (maze.getWidth() / 2) * 2 + 1;
            _y = rand() % (maze.getHeight() / 2) * 2 + 1;
        }
        maze.at(_x, _y) = 'X';
    }

    void move(Maze& maze, Player& player) {
        steps++;
        if (steps % _speed == 0) {
            direction = rand() % 4;
            if (direction == 0 && maze.at(_x - 1, _y) != '#') {
                maze.at(_x, _y) = ' ';
                _x--;
            }
            else if (direction == 1 && maze.at(_x + 1, _y) != '#') {
                maze.at(_x, _y) = ' ';
                _x++;
            }
            else if (direction == 2 && maze.at(_x, _y - 1) != '#') {
                maze.at(_x, _y) = ' ';
                _y--;
            }
            else if (direction == 3 && maze.at(_x, _y + 1) != '#') {
                maze.at(_x, _y) = ' ';
                _y++;
            }
            if (player.getX() == _x && player.getY() == _y) {
                player.minusHp();
            }
            maze.at(_x, _y) = 'X';
        }
    }

    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }
};

int main() {
    Maze maze(WIDTH, HEIGHT);
    Player player(maze);
    Item* item = new Item(maze);
    Enemy enemy(maze);

    while (true) {
        maze.display();
        std::cout << player.getHp() << std::endl;
        player.move(maze, item);
        enemy.move(maze, player);

        if (player.getHp() <= 0) {
            std::cout << "Game Over!" << std::endl;
            break;
        }

        if (player.getX() == maze.returnb() && player.getY() == maze.returna()) {
            std::cout << "You win!" << std::endl;
            break;
        }
    }

    return 0;
}
