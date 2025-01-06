#include <iostream>
#include <cstring>

class Item {
public:
    virtual ~Item() = default;
    virtual const char* get_description() const = 0;
    virtual void effect() const = 0;
    virtual void use() const = 0;
};

class Stick : public Item {
private:
    char* attack_boost;
    char* description;

public:
    Stick(char* attack) {
        attack_boost = new char[strlen(attack) + 1];
        strcpy(attack_boost, attack);
        description = new char[strlen("Wooden stick") + 1];
        strcpy(description, "Wooden stick");
    }

    void use() const override {
        std::cout << "Swung the stick\n";
    }

    const char* get_description() const override {
        return description;
    }

    void effect() const override {
        std::cout << "Attack boost " << attack_boost << '\n';
    }

    ~Stick() override {
        delete[] description;
    }
};

class Food : public Item {
private:
    char* health_restoration;
    char* description;

public:
    Food(char* health) {
        health_restoration = new char[strlen(health) + 1];
        strcpy(health_restoration, health);
        description = new char[strlen("Tasty food") + 1];
        strcpy(description, "Tasty food");
    }

    void use() const override {
        std::cout << "Ate the food\n";
    }

    const char* get_description() const override {
        return description;
    }

    void effect() const override {
        std::cout << "Health restore " << health_restoration << '\n';
    }

    ~Food() override {
        delete[] description;
    }
};

class Potion : public Item {
private:
    char* attribute_bonus;
    int duration;
    char* description;

public:
    Potion(char* bonus, int time) :  duration(time) {
        attribute_bonus = new char[strlen(bonus) + 1];
        strcpy(attribute_bonus, bonus);
        description = new char[strlen("Strong elixir") + 1];
        strcpy(description, "Strong elixir");
    }

    void use() const override {
        std::cout << "Used the potion\n";
    }

    const char* get_description() const override {
        return description;
    }

    void effect() const override {
        std::cout << "Bonus " << attribute_bonus << " lasts " << duration << '\n';
    }

    ~Potion() override {
        delete[] description;
    }
};

class Armor : public Item {
private:
    char* defense_boost;
    char* description;

public:
    Armor(char* defense){
        defense_boost = new char[strlen(defense) + 1];
        strcpy(defense_boost, defense);
        description = new char[strlen("Protective armor") + 1];
        strcpy(description, "Protective armor");
    }

    void use() const override {
        std::cout << "Equipped the armor\n";
    }

    const char* get_description() const override {
        return description;
    }

    void effect() const override {
        std::cout << "Defense boost " << defense_boost << '\n';
    }

    ~Armor() override {
        delete[] description;
    }
};

class Inventory {
private:
    Item* items[10];
    int item_count;

public:
    Inventory() : item_count(0) {}

    ~Inventory() {
        for (int i = 0; i < item_count; ++i) {
            delete items[i];
        }
    }

    void add_item(Item* item) {
        if (item_count < 10) {
            items[item_count + 1] = item;
        } else {
            std::cout << "Inventory full\n";
        }
        item_count = item_count + 1;
    }

    void use_all_items() const {
        for (int i = 0; i < item_count; ++i) {
            items[i]->use();
        }
    }

    void describe_all_items() const {
        for (int i = 0; i < item_count; ++i) {
            std::cout << items[i]->get_description() << '\n';
        }
    }
};

int main() {
    Food* food = new Food("");
    Stick* stick = new Stick("");
    Potion* potion = new Potion("", 3);
    Armor* armor = new Armor("");

    Inventory inventory;
    inventory.add_item(food);
    inventory.add_item(stick);
    inventory.add_item(potion);
    inventory.add_item(armor);

    std::cout << "Item descriptions:\n";
    inventory.describe_all_items();

    std::cout << "Using items:\n";
    inventory.use_all_items();

    return 0;
}
