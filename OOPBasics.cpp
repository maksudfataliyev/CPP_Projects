#include <iostream>
#include <cstring>

class Grocery {
private:
    char* _name;
    char* _type;
    float _price;
public:
    Grocery() : _name(nullptr), _type(nullptr), _price(0) {}
    Grocery(char* name, char* type, float price) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);

        _type = new char[strlen(type) + 1];
        strcpy(_type, type);

        _price = price;
    }


    // getters
    char* get_name() const { return _name; }
    char* get_type() const { return _type; }
    float get_price() const { return _price; }

    //setters
    void set_name(char* other) {
        if (other != nullptr) {
            delete[] _name;
            _name = new char[strlen(other) + 1];
            strcpy(_name, other);
        }
    }
    void set_type(char* other) {
        if (other != nullptr) {
            delete[] _type;
            _type = new char[strlen(other) + 1];
            strcpy(_type, other);
        }
    }
    void set_price(float other) {
        if (other >= 0) {
            _price = other;
        }
    }
};

class Market {
private:
    char* _name;
    Grocery* _groceries;
    size_t _capacity;
    size_t _count;

public:
    Market(char* name, size_t capacity) : _capacity(capacity), _count(0) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);

        _groceries = new Grocery[_capacity];
    }

    Grocery* get_arr() const { return _groceries; }

    void add_grocery(const Grocery& ggg, size_t index) {
        if (_count >= _capacity || index > _count) {
            std::cout << "Cannot add grocery. Index out of bounds or capacity reached." << std::endl;
            return;
        }

        for (size_t i = _count; i > index; --i) {
            _groceries[i] = _groceries[i - 1];
        }

        _groceries[index] = ggg;
        _count++;
    }

    void remove_grocery(size_t index) {
        if (index >= _count) {
            std::cout << "Index out of bounds." << std::endl;
            return;
        }

        for (size_t i = index; i < _count - 1; ++i) {
            _groceries[i] = _groceries[i + 1];
        }

        _count--;
    }

    size_t find(const char* namee) const {
        for (size_t i = 0; i < _count; ++i) {
            if (strcmp(_groceries[i].get_name(), namee) == 0) {
                return i;
            }
        }
        return -1;
    }

    void print_groceries() const {
        for (size_t i = 0; i < _count; i++) {
            std::cout << "Name: " << _groceries[i].get_name() << std::endl;
            std::cout << "Type: " << _groceries[i].get_type() << std::endl;
            std::cout << "Price: " << _groceries[i].get_price() << std::endl;
        }
    }
};

int main() {
    char market_name[50] = "Aftandil";
    Market market(market_name, 10);

    char grocery_name1[50] = "Apple";
    char grocery_type1[50] = "Fruit";
    Grocery grocery1(grocery_name1, grocery_type1, 1.23);

    char grocery_name2[50] = "Banana";
    char grocery_type2[50] = "Fruit";
    Grocery grocery2(grocery_name2, grocery_type2, 0.99);

    market.add_grocery(grocery1, 0);
    market.add_grocery(grocery2, 1);

    std::cout << "Groceries after adding:" << std::endl;
    market.print_groceries();

    size_t index = market.find("Apple");
    if (index >= 0) {
        std::cout << "Found 'Apple' at index: " << index << std::endl;
    }
    else {
        std::cout << "'Apple' not found" << std::endl;
    }

    market.remove_grocery(0);

    std::cout << "Groceries after removal:" << std::endl;
    market.print_groceries();

    return 0;
}
