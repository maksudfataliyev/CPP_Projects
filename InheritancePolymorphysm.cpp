#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string.h>

class Skill {
protected:
    char _skill_name[20];
    char _skill_type[10];
    unsigned int _mana_cost;
public:
    Skill() {}
    Skill(char skill_name[20], char skill_type[10], unsigned int mana_cost) {
        _mana_cost = mana_cost;
        strcpy(_skill_name, skill_name);
        if (strcmp(skill_type, "defense") != 0 && strcmp(skill_type, "attack") != 0 && strcmp(skill_type, "support") != 0) {
            printf("Incorrect skill type\n");
            strcpy(_skill_type, "undefined");
        }
        else {
            strcpy(_skill_type, skill_type);
        }
    }
    unsigned int get_mana_cost() {
        return _mana_cost;
    }
    char* get_skill_name() {
        return _skill_name;
    }
    char* get_skill_type() {
        return _skill_type;
    }
    void display_skill() const {
        printf("Skill name: %s\n", _skill_name);
        printf("Skill type: %s\n", _skill_type);
        printf("Mana cost: %u\n", _mana_cost);
    }
    virtual ~Skill() {}
};

class Character {
protected:
    Skill* _skills;
    unsigned int _capacity = 0;
    unsigned int _xp = 0;
public:
    Character() { _skills = nullptr; }
    virtual void useSkill() = 0;
    void addSkill(Skill &skill) {
        Skill* temp = new Skill[_capacity + 1];
        for (int i = 0; i < _capacity; i++) temp[i] = _skills[i];
        temp[_capacity] = skill;
        _capacity++;
        delete[] _skills;
        _skills = temp;
    }
    Skill* getSkills() {
        return _skills;
    }
    unsigned int getSkillCount() {
        return _capacity;
    }
    void levelUp() {
        _xp = _xp + 10;
    }
    virtual ~Character() {
        delete[] _skills;
    }
};

class Tank : public Character {
public:
    void useSkill() override {
        size_t mana = 0;
        for (int i = 0; i < _capacity; i++) {
            mana += _skills[i].get_mana_cost();
            if (strcmp(_skills[i].get_skill_type(), "attack") == 0) {
                printf("Attack skill used: %s\n", _skills[i].get_skill_name());
            }
            else if (strcmp(_skills[i].get_skill_type(), "defense") == 0) {
                printf("Defense skill used: %s\n", _skills[i].get_skill_name());
            }
        }
        printf("Total mana used: %zu\n", mana);
    }
    void levelUp() {
        _xp += 20;
    }
};

class Mage : public Character {
public:
    void useSkill() override {
        size_t mana = 0;
        for (int i = 0; i < _capacity; i++) {
            mana += _skills[i].get_mana_cost();
            if (strcmp(_skills[i].get_skill_type(), "attack") == 0) {
                printf("Attack skill used: %s\n", _skills[i].get_skill_name());
            }
            else if (strcmp(_skills[i].get_skill_type(), "defense") == 0) {
                printf("Defense skill used: %s\n", _skills[i].get_skill_name());
            }
        }
        printf("Total mana used: %zu\n", mana);
    }
    void levelUp() {
        _xp = _xp + 15;
    }
};

class Thief : public Character {
public:
    void useSkill() override {
        size_t mana = 0;
        for (int i = 0; i < _capacity; i++) {
            mana += _skills[i].get_mana_cost();
            if (strcmp(_skills[i].get_skill_type(), "attack") == 0) {
                printf("Attack skill used: %s\n", _skills[i].get_skill_name());
            }
            else if (strcmp(_skills[i].get_skill_type(), "defense") == 0) {
                printf("Defense skill used: %s\n", _skills[i].get_skill_name());
            }
        }
        printf("Total mana used: %zu\n", mana);
    }
    void levelUp() {
        _xp = _xp + 10;
    }
};

class Healer : public Character {
public:
    void useSkill() override {
        size_t mana = 0;
        for (int i = 0; i < _capacity; i++) {
            mana += _skills[i].get_mana_cost();
            if (strcmp(_skills[i].get_skill_type(), "attack") == 0) {
                printf("Attack skill used: %s\n", _skills[i].get_skill_name());
            }
            else if (strcmp(_skills[i].get_skill_type(), "defense") == 0) {
                printf("Defense skill used: %s\n", _skills[i].get_skill_name());
            }
        }
        printf("Total mana used: %zu\n", mana);
    }
    void levelUp() {
        _xp = _xp + 12;
    }
};

class Battle {
public:
    void attack(Character& attacker) {
        printf("Attack initiated.\n");
        size_t mana = 0;
        for (int i = 0; i < attacker.getSkillCount(); i++) {
            if (strcmp(attacker.getSkills()[i].get_skill_type(), "attack") == 0) {
                mana += attacker.getSkills()[i].get_mana_cost();
                printf("Attack skill used: %s\n", attacker.getSkills()[i].get_skill_name());
            }
        }
        printf("Total mana used for attack: %zu\n", mana);
    }

    void defend(Character& defender) {
        printf("Defense action.\n");
        size_t mana = 0;
        for (int i = 0; i < defender.getSkillCount(); i++) {
            if (strcmp(defender.getSkills()[i].get_skill_type(), "defense") == 0) {
                mana += defender.getSkills()[i].get_mana_cost();
                printf("Defense skill used: %s\n", defender.getSkills()[i].get_skill_name());
            }
        }
        printf("Total mana used for defense: %zu\n", mana);
    }
};

int main() {
    return 0;
}
