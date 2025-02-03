#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value, Node* p = nullptr, Node* n = nullptr) : data(value), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& value) {
        if (!tail) {
            head = tail = new Node(value);
        } else {
            tail = tail->next = new Node(value, tail, nullptr);
        }
        size++;
    }

    void push_front(const T& value) {
        if (!head) {
            head = tail = new Node(value);
        } else {
            head = head->prev = new Node(value, nullptr, head);
        }
        size++;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
    }

    void print() const {
        for (Node* temp = head; temp; temp = temp->next) {
            std::cout << temp->data << " ";
        }
        std::cout << std::endl;
    }

    int get_size() const {
        return size;
    }
};
