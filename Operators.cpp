#include <iostream>

int main() {
    char choice;
    int num1, num2;
    int result;
    std::cout<<"+,-,/(bez ostatka),*" << std::endl;
    std::cin >> choice;
    std::cout<<"Numbers:" << std::endl;
    std::cin >> num1 >> num2;
    switch (choice) {
        case '+':
            result = num1 + num2;
        std::cout<<"Result:"<<result<<std::endl;
        break;
        case '-':
            result = num1 - num2;
        std::cout<<"Result:"<<result<<std::endl;
        break;
        case '*':
            result = num1 * num2;
        std::cout<<"Result:"<<result<<std::endl;
        break;
        case '/':
            result = num1 / num2;
        std::cout<<"Result:"<<result<<std::endl;
        break;
        default:
            std::cout<<"Wrong choice!"<<std::endl;
        break;
    }
}
