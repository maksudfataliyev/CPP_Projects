#include <iostream>
#include <cstring>

class MyString {
private:
    char* _str;
public:
    void enterstr(const char* str) {
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }

    MyString(const MyString& other) {
        if (other._str) {
            _str = new char[strlen(other._str) + 1];
            strcpy(_str, other._str);
        }
        else {
            _str = nullptr;
        }
    }

    MyString& operator = (const MyString& str) {
        if (this == &str) {
            return *this;
        }
        delete[] _str;
        if (_str) {
            _str = new char[strlen(str._str) + 1];
            strcpy(_str, str._str);
            return *this;
        }
        else {
            _str = nullptr;
            return *this;
        }
    }

    MyString& operator = (MyString&& str) noexcept{
        if (this != &str) {
            delete[] _str;
            _str = str._str;
            str._str = nullptr;
        }
        return *this;
    }

    unsigned int length() const {
        return strlen(_str);
    }
    void append(char* str) {
        int i = 0;
        int a = strlen(_str);
        _str = new char[strlen(_str) + strlen(str) + 1];
        while(true) {
            if (str[i] == '\0') {
                return;
            }
            else {
                _str[a + 1 + i] = str[i];
            }
        }
    }
    ~MyString() {
        delete[] _str;
    }

    char* substring(int start, int len) {
        int b = 0;
        char* str = new char[len + start + 1];
        for (int i = start; i < len + start; i++) {
            str[b] = _str[i];
            b = b + 1;
        }
        str[len  + start + 1] = '\0';
        return str;
    }
    int find(const char* str) {
        char* pos = strstr(_str, str);
        if (pos) {
            return pos - _str;
        }
        return -1;
    }

    void to_upper() {
        for (int i = 0; _str[i]; i++) {
            if (_str[i] >= 'a' && _str[i] <= 'z') {
                _str[i] = _str[i] - 32;
            }
        }
    }

};

int main() {
};
