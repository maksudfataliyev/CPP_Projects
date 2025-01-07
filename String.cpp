#include <iostream>
#include <cstring>


char* strcpy_S(char* newarr, unsigned int size_new, const char* oldarr) {
    if (oldarr == nullptr) {
        return newarr;
    }
    for (unsigned int i = 0; i < size_new; i++) {
        newarr[i] = oldarr[i];
    }

    return newarr;
}

char* strcat_S(char* dest, size_t size, const char* src) {
    if (src == nullptr) {
        return dest;
    }

    unsigned int i = 0;

    while (dest[i] != '\0' && i < size - 1) {
        i++;
    }

    unsigned int a = 0;
    while (src[a] != '\0' && i < size - 1) {
        dest[i] = src[a];
        i++;
        a++;
    }

    dest[i] = '\0';
    return dest;
}

unsigned int strlen_(const char* arr) {
    unsigned int length = 0;
    while (arr[length] != '\0') {
        length = length + 1;
    }
    return length;
}

char* strstr(const char* a, const char* b) {
    if (*b == '\0') return (char*)a;

    while (*a != '\0') {
        const char* h = a;
        const char* n = b;

        while (*h == *n && *n != '\0') {
            h++;
            n++;
        }

        if (*n == '\0') return (char*)b;

        b++;
    }
    return nullptr;
}

char* strchr(const char* str, int c) {
    for (unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return (char*)str;
        }
    }
    return nullptr;
}

int main() {
}
