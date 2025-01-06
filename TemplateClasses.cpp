#include <iostream>

template <typename T>
class MyVector {
private:
    T* elements;
    size_t currentSize;
    size_t maxCapacity;

    void resize(size_t newCapacity) {
        T* temp = new T[newCapacity];
        for (size_t i = 0; i < currentSize; i++) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
        maxCapacity = newCapacity;
    }

public:
    MyVector() : elements(nullptr), currentSize(0), maxCapacity(0) {}

    ~MyVector() {
        delete[] elements;
    }

    void append(const T& value) {
        if (currentSize == maxCapacity) {
            if (maxCapacity == 0) {
                resize(1);
            }
            else{
                resize(maxCapacity +  1);
            }
        }
        elements[currentSize] = value;
        currentSize++;
    }

    T popBack(bool& success) {
        if (currentSize == 0) {
            success = false;
            return T();
        }
        currentSize--;
        success = true;
        return elements[currentSize];
    }

    bool contains(const T& value) const {
        for (size_t i = 0; i < currentSize; i++) {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

    void reverse() {
        size_t start = 0;
        size_t end = currentSize - 1;
        while (start < end) {
            T temp = elements[start];
            elements[start] = elements[end];
            elements[end] = temp;
            start = start + 1;
            end = end - 1;
        }
    }

    MyVector<T> copy() const {
        MyVector<T> newVector;
        newVector.resize(maxCapacity);
        newVector.currentSize = currentSize;
        for (size_t i = 0; i < currentSize; i++) {
            newVector.elements[i] = elements[i];
        }
        return newVector;
    }

    bool operator==(const MyVector<T>& other) const {
        if (currentSize != other.currentSize) {
            return false;
        }
        for (size_t i = 0; i < currentSize; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyVector<T>& other) const {
        if (currentSize != other.currentSize) {
            return true;
        }
        for (size_t i = 0; i < currentSize; i++) {
            if (elements[i] != other.elements[i]) {
                return true;
            }
        }
        return false;
    }

    void sort() {
        for (size_t i = 0; i < currentSize - 1; i++) {
            for (size_t j = 0; j < currentSize - i - 1; j++) {
                if (elements[j] > elements[j + 1]) {
                    T temp = elements[j];
                    elements[j] = elements[j + 1];
                    elements[j + 1] = temp;
                }
            }
        }
    }


    void swap(MyVector<T>& other) {
        T* tempElements = elements;
        size_t tempSize = currentSize;
        size_t tempCapacity = maxCapacity;

        elements = other.elements;
        currentSize = other.currentSize;
        maxCapacity = other.maxCapacity;

        other.elements = tempElements;
        other.currentSize = tempSize;
        other.maxCapacity = tempCapacity;
    }

    void print() const {
        for (size_t i = 0; i < currentSize; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << "\n";
    }

    size_t getSize() const {
        return currentSize;
    }

    size_t getCapacity() const {
        return maxCapacity;
    }
};

int main() {

    return 0;
}
