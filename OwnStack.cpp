#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int size;

    void resize() {
        capacity = capacity * 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i = i + 1) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Stack(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size = size + 1;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        size = size - 1;
    }

    T top() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data[size - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack<int> s;
    bool a = true;
    while (a) {
        try {
            int choice;
            std::cout << "push(0) pop(1) top(2) isEmpty(3) getSize(4) exit(5)" << std::endl;
            std::cin >> choice;
            switch (choice) {
                case 0: {
                    int num;
                    std::cout << "Enter the number to be pushed: ";
                    std::cin >> num;
                    s.push(num);
                    break;
                }
                case 1:
                    std::cout << "Deleting the top" << std::endl;
                    s.pop();
                    break;
                case 2:
                    std::cout << "Top: " << s.top() << std::endl;
                    break;
                case 3:
                    std::cout << "Is empty: " << s.isEmpty() << std::endl;
                    break;
                case 4:
                    std::cout << "Size: " << s.getSize() << std::endl;
                    break;
                case 5:
                    std::cout << "Closing the app" << std::endl;
                    a = false;
                    break;
                default:
                    std::cout << "Invalid choice" << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
    }
    return 0;
}