#include <iostream>
#include <cstring>
#include <stdexcept>

class BookNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Book not found in the library.";
    }
};

class LibraryCapacityExceededException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Library capacity exceeded.";
    }
};

class Item {
protected:
    char* title;
public:
    Item() : title(nullptr) {}

    Item(const char* _title) {
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);
    }

    virtual ~Item() {
        delete[] title;
    }

    virtual void getInfo() const = 0;

    const char* getTitle() const {
        return title;
    }
};

class Book : public Item {
private:
    char* author;
    int publicationYear;
public:
    Book(const char* _title, const char* _author, int _publicationYear)
        : Item(_title), publicationYear(_publicationYear) {
        author = new char[strlen(_author) + 1];
        strcpy(author, _author);
    }

    void getInfo() const override {
        std::cout << "Title: " << title << "\nAuthor: " << author
                  << "\nPublication Year: " << publicationYear << std::endl;
    }

    ~Book() override {
        delete[] author;
    }
};

class Library {
private:
    Item** items;
    int size;
    int capacity;
public:
    Library(int _capacity) : capacity(_capacity), size(0) {
        items = new Item*[capacity];
    }

    ~Library() {
        for (int i = 0; i < size; i++) {
            delete items[i];
        }
        delete[] items;
    }

    void addItem(Item* item) {
        if (size >= capacity) {
            throw LibraryCapacityExceededException();
        }
        items[size++] = item;
    }

    void removeItem(const char* title) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (strcmp(items[i]->getTitle(), title) == 0) {
                delete items[i];
                for (int j = i; j < size - 1; j++) {
                    items[j] = items[j + 1];
                }
                size--;
                found = true;
                break;
            }
        }
        if (!found) {
            throw BookNotFoundException();
        }
    }

    void listItems() const {
        if (size == 0) {
            std::cout << "The library is empty." << std::endl;
        } else {
            for (int i = 0; i < size; i++) {
                items[i]->getInfo();
            }
        }
    }
};

class LibraryManager {
private:
    Library library;
public:
    LibraryManager(int capacity) : library(capacity) {}

    void mainMenu() {
        int choice;
        while (true) {
            std::cout << "Library Menu:\n1. Add Book\n2. Remove Book\n3. List Items\n4. Exit\nChoose an option: ";
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1) {
                char title[100], author[100];
                int publicationYear;
                std::cout << "Enter book title: ";
                std::cin.getline(title, 100);
                std::cout << "Enter author: ";
                std::cin.getline(author, 100);
                std::cout << "Enter publication year: ";
                std::cin >> publicationYear;
                std::cin.ignore();

                try {
                    library.addItem(new Book(title, author, publicationYear));
                    std::cout << "Book added successfully.\n";
                } catch (const LibraryCapacityExceededException& e) {
                    std::cerr << e.what() << std::endl;
                }
            } else if (choice == 2) {
                char title[100];
                std::cout << "Enter book title to remove: ";
                std::cin.getline(title, 100);

                try {
                    library.removeItem(title);
                    std::cout << "Book removed successfully.\n";
                } catch (const BookNotFoundException& e) {
                    std::cerr << e.what() << std::endl;
                }
            } else if (choice == 3) {
                library.listItems();
            } else if (choice == 4) {
                std::cout << "Exiting the library manager.\n";
                break;
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    LibraryManager manager(5);

    try {
        manager.mainMenu();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
