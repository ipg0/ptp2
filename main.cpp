#include <iostream>
#include <iomanip>
#include <string>

void menu(long long &temp) {
    std::cout << "Super Useful Oct-Base Calculator:" << std::endl
        << "Current value: " << temp << std::endl
        << "1) Add" << std::endl
        << "2) Subtract" << std::endl
        << "3) Reset" << std::endl
        << "Select an option [1-3]: ";
    char opcode;
    std::cin >> opcode;
    
}

void input(std::string &promt = "", long long &num) {
    std::cout << promt << ": ";
    std::cin >> std::oct >> num >> std::dec;
}

void output(std::string &promt = "", long long num) {
    std::cout << promt << ": " << std::oct << num << std::dec << std::endl;
}

void add(long long &a, long long b) {
    a += b;
}

void sub(long long &a, long long b) {
    a -= b;
}

void reset(long long &a) {
    a = 0;
}

int main() {
    long long temp;
    reset(temp);
}