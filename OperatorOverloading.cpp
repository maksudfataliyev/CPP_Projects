#include <cstring>
#include <iostream>

class String {
private:
    char* _str;
    size_t _length;

public:
    String(const char* str = "") : _length(strlen(str)) {
        _str = new char[_length + 1];
        strcpy(_str, str);
    }

    String(const String& other) : _length(other._length) {
        _str = new char[_length + 1];
        strcpy(_str, other._str);
    }

    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }

        delete[] _str;
        _length = other._length;
        _str = new char[_length + 1];
        strcpy(_str, other._str);
        return *this;
    }

    String operator+(const String& other) const {
        char* newStr = new char[_length + other._length + 1];
        strcpy(newStr, _str);
        strcat(newStr, other._str);

        String result(newStr);
        delete[] newStr;
        return result;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(_str, other._str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    String operator*(int times) const {
        if (times <= 0) {
            return String("");
        }

        size_t newlen = _length * times;
        char* newStr = new char[newlen + 1];
        newStr[0] = '\0';

        for (int i = 0; i < times; ++i) {
            strcat(newStr, _str);
        }

        String result(newStr);
        delete[] newStr;
        return result;
    }

    String operator/(size_t length) const {
        if (length >= _length) {
            return String("");
        }

        char* newStr = new char[_length - length + 1];
        for (size_t i = 0; i < _length - length; ++i) {
            newStr[i] = *this[i];
        }
        newStr[_length - length] = '\0';

        String result(newStr);
        delete[] newStr;
        return result;
    }

    ~String() {
        delete[] _str;
    }

};

int main() {
    return 0;
}
