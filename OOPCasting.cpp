#include <iostream>
#include <string>

class Transport {
protected:
    std::string model;
    int velocity;
public:
    Transport(std::string m, int v) : model(m), velocity(v) {}
    virtual ~Transport() {}
    virtual void show() const {
        std::cout << "Transport: " << model << ", velocity: " << velocity << " km/h\n";
    }
};

class Auto : public Transport {
    int doorCount;
    bool hasAC;
public:
    Auto(std::string m, int v, int d, bool ac) : Transport(m, v), doorCount(d), hasAC(ac) {}
    void show() const override {
        Transport::show();
        std::cout << "Doors: " << doorCount << ", AC: " << (hasAC ? "yes" : "no") << "\n";
    }
    Transport* convertToTransport() {
        return static_cast<Transport*>(this);
    }
};

class Bike : public Transport {
    std::string handleStyle;
public:
    Bike(std::string m, int v, std::string hs) : Transport(m, v), handleStyle(hs) {}
    void show() const override {
        Transport::show();
        std::cout << "Handle style: " << handleStyle << "\n";
    }
};

void verifyAuto(Transport* t) {
    Auto* autoPtr = dynamic_cast<Auto*>(t);
    if (autoPtr) {
        autoPtr->show();
    } else {
        std::cout << "This is not an auto.\n";
    }
}

void applyReinterpretCast(Transport* t) {
    Auto* autoPtr = reinterpret_cast<Auto*>(t);
    autoPtr->show();
}

int main() {
    Auto sedan("Toyota Corolla", 140, 4, true);
    Bike motorbike("Ducati Monster", 280, "racing");

    std::cout << "Created an auto:\n";
    sedan.show();

    std::cout << "\nCreated a bike:\n";
    motorbike.show();

    std::cout << "\nVerifying auto:\n";
    verifyAuto(&sedan);
    verifyAuto(&motorbike);

    std::cout << "\nUsing static_cast:\n";
    Transport* t = sedan.convertToTransport();
    t->show();

    std::cout << "\nUsing reinterpret_cast:\n";
    applyReinterpretCast(t);

    return 0;
}
