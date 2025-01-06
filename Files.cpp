#include <iostream>
#include <cstring>
#include <stdio.h>

struct Book {
    char name[20];
    char author[20];
    unsigned int published_year;
    char genre[20];
    bool exists_or_not;
};

struct Library {
    Book books[100];
    unsigned int book_counter;
};

void write_library_to_file(const char* filename, const Library& library) {
    FILE* file = nullptr;
    fopen_s(&file, filename, "wb");
    if (file == nullptr) {
        std::cout << "Error opening file for writing!" << std::endl;
        return;
    }
    fwrite(&library, sizeof(Library), 1, file);
    fclose(file);
}

void read_library_from_file(const char* filename, Library& library) {
    FILE* file = nullptr;
    fopen_s(&file, filename, "rb");
    if (file == nullptr) {
        std::cout << "Error opening file for reading!" << std::endl;
        return;
    }
    fread(&library, sizeof(Library), 1, file);
    fclose(file);
}

void add_book(Library& library, const Book& new_book) {
    unsigned short new_book_index;
    for (int i = 0; i < 100; i++) {
        if (!library.books[i].exists_or_not) {
            new_book_index = i;
            break;
        }
        if (i == 99) {
            new_book_index = 101;
        }
    }
    if (new_book_index == 101) {
        std::cout << "Library is full" << std::endl;
        return;
    }
    library.books[new_book_index] = new_book;
    library.books[new_book_index].exists_or_not = true;
    library.book_counter++;
}

void delete_book(Library& library, const Book& del_book) {
    unsigned short delete_book_index = 101;
    for (int i = 0; i < 100; i++) {
        if (library.books[i].exists_or_not &&
            strcmp(library.books[i].author, del_book.author) == 0 &&
            strcmp(library.books[i].genre, del_book.genre) == 0 &&
            strcmp(library.books[i].name, del_book.name) == 0) {
            delete_book_index = i;
            break;
        }
    }
    if (delete_book_index == 101) {
        std::cout << "There is no such a book" << std::endl;
        return;
    }
    library.books[delete_book_index].exists_or_not = false;
    library.book_counter--;
}

void update_book_info(Library& library, const char* book_name, const char* field_name, const char* new_value) {
    char temp_book_name[20];
    strcpy(temp_book_name, book_name);

    for (int i = 0; temp_book_name[i]; i++) {
        if (temp_book_name[i] >= 'A' && temp_book_name[i] <= 'Z') {
            temp_book_name[i] += 32;
        }
    }

    for (unsigned int i = 0; i < 100; i++) {
        char temp_name_in_array[20];
        strcpy(temp_name_in_array, library.books[i].name);

        for (int j = 0; temp_name_in_array[j]; j++) {
            if (temp_name_in_array[j] >= 'A' && temp_name_in_array[j] <= 'Z') {
                temp_name_in_array[j] += 32;
            }
        }

        if (strcmp(temp_name_in_array, temp_book_name) == 0) {
            if (strcmp(field_name, "author") == 0) {
                strcpy(library.books[i].author, new_value);
            } else if (strcmp(field_name, "published_year") == 0) {
                library.books[i].published_year = atoi(new_value);
            } else if (strcmp(field_name, "genre") == 0) {
                strcpy(library.books[i].genre, new_value);
            } else if (strcmp(field_name, "exists_or_not") == 0) {
                library.books[i].exists_or_not = (strcmp(new_value, "1") == 0);
            } else if (strcmp(field_name, "name") == 0) {
                strcpy(library.books[i].name, new_value);
            }
            break;
        }
    }
}

void search_book(const Library& library, const char* name) {
    char newname[20];
    strcpy(newname, name);

    for (int i = 0; newname[i] != '\0'; i++) {
        if (newname[i] >= 'A' && newname[i] <= 'Z') {
            newname[i] += ('a' - 'A');
        }
    }

    bool found = false;
    for (unsigned int i = 0; i < 100; ++i) {
        if (library.books[i].exists_or_not) {
            char temp_name_in_array[20];
            strcpy(temp_name_in_array, library.books[i].name);

            for (int j = 0; temp_name_in_array[j]; j++) {
                if (temp_name_in_array[j] >= 'A' && temp_name_in_array[j] <= 'Z') {
                    temp_name_in_array[j] += ('a' - 'A');
                }
            }

            if (strstr(temp_name_in_array, newname) != nullptr) {
                std::cout << "Found book: " << std::endl;
                std::cout << "Name: " << library.books[i].name << std::endl;
                std::cout << "Author: " << library.books[i].author << std::endl;
                std::cout << "Genre: " << library.books[i].genre << std::endl;
                std::cout << "Published Year: " << library.books[i].published_year << std::endl;
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "Book not found." << std::endl;
    }
}

void print_books(const Library& library) {
    for (int i = 0; i < 100; i++) {
        if (library.books[i].exists_or_not) {
            std::cout << "Author: " << library.books[i].author << std::endl;
            std::cout << "Name: " << library.books[i].name << std::endl;
            std::cout << "Genre: " << library.books[i].genre << std::endl;
            std::cout << "Published Year: " << library.books[i].published_year << std::endl;
            std::cout << std::endl;
        }
    }
}

int main() {
    unsigned short choice;
    Library library;
    library.book_counter = 0;

    for (int i = 0; i < 100; i++) {
        library.books[i].exists_or_not = false;
    }

    read_library_from_file("library.bin", library);

    while (true) {
        std::cout << "What do you want to do: Add(1), delete(2), change info(3), search(4), print all books(5), save to file(6), exit(7)" << std::endl;
        std::cin >> choice;
        std::cin.ignore();

        while (choice < 1 || choice > 7) {
            std::cout << "Wrong input. Try again." << std::endl;
            std::cin >> choice;
        std::cin.ignore();
        }

        switch (choice) {
            case 1: {
                Book newbook;
                std::cout << "What is the name of the book: ";
                std::cin.getline(newbook.name, 20);
                std::cout << "Who is the author of the book: ";
                std::cin.getline(newbook.author, 20);
                std::cout << "In what year was the book published: ";
                std::cin >> newbook.published_year;
                std::cout << "What is the genre of the book: ";
                std::cin.getline(newbook.genre, 20);
                newbook.exists_or_not = true;
                add_book(library, newbook);
                break;
            }
            case 2: {
                Book delbook;
                std::cout << "What is the name of the book: ";
                std::cin.getline(delbook.name, 20);
                std::cout << "Who is the author of the book: ";
                std::cin.getline(delbook.author, 20);
                std::cout << "What is the genre of the book: ";
                std::cin.getline(delbook.genre, 20);
                delete_book(library, delbook);
                break;
            }
            case 3: {
                char book_name[20];
                char field_name[20];
                char new_value[20];

                std::cout << "Enter the name of the book to update: ";
                std::cin.getline(book_name, 20);
                std::cout << "Enter the field to update (author/published_year/genre/exist/name): ";
                std::cin.getline(field_name, 20);
                std::cout << "Enter the new value: ";
                std::cin.getline(new_value, 20);

                update_book_info(library, book_name, field_name, new_value);
                break;
            }
            case 4: {
                char search_name[20];
                std::cout << "Enter the name of the book to search: ";
                std::cin.getline(search_name, 20);
                search_book(library, search_name);
                break;
            }
            case 5: {
                print_books(library);
                break;
            }
            case 6: {
                write_library_to_file("library.bin", library);
                break;
            }
            case 7: {
                return 0;
            }
        }
    }
}
