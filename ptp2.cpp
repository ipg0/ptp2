#include <iostream>
#include <cstring>

const long len = 12;
const short base = 8;

short d(char c) {
    return static_cast<short>(c - '0');
}

char c(short d) {
    return static_cast<char>(d) + '0';
}

void add(char *a, char *b) {
    char result[len + 1];
    bool carry = false;
    for(long i = len - 1; i >= 0; --i) {
        result[i] = c((d(a[i]) + d(b[i]) + static_cast<short>(carry)) % base);
        carry = static_cast<bool>((d(a[i]) + d(b[i]) + static_cast<short>(carry)) / base);
    }
    if(carry)
        std::cout << "Overflow!" << std::endl;
    result[len] = '\0';
    strcpy(a, result);
}

void sub(char *a, char *b) {
    char result[len + 1];
    bool carry = false;
    for(long i = len - 1; i >= 0; --i) {
        bool new_carry = false;
        new_carry = (d(a[i]) - static_cast<short>(carry) < d(b[i]));
        result[i] = c(d(a[i]) + base * static_cast<short>(new_carry) - static_cast<short>(carry) - d(b[i]));
        carry = new_carry;
    }
    if(carry)
        std::cout << "Underflow!" << std::endl;
    result[len] = '\0';
    strcpy(a, result);
}

void show_menu(char *num) {
    std::cout << "Current value: ";
    long i = 0;
    while(i < len && num[i] == '0')
        ++i;
    if(i == len)
        --i;
    for(; i < len; i++) {
        std::cout << num[i];
    }
    std::cout << std::endl << "1) Add a number"
        << std::endl << "2) Subtract a number"
        << std::endl << "3) Reset"
        << std::endl << "0) Quit"
        << std::endl << "Select an option [0-3]: ";
}

void format(char *num) {
    char result[len + 1];
    for(long i = static_cast<long>(len - strlen(num) - 1); i >= 0; --i)
        result[i] = '0';
    for(long i = 0; i < strlen(num); i++)
        result[len - strlen(num) + i] = num[i];
    result[len] = '\0';
    strcpy(num, result);
}

void reset(char *num) {
    for(long i = 0; i < len; i++)
        num[i] = '0';
    num[len] = '\0';
}

#ifdef _WIN32

void clear() {
    system("cls");
}

#else

void clear() {
    system("clear");
}

#endif

int main(void) {
    char num[len + 1], new_num[len + 1];
    char query = '\0';
    reset(num);
    while(query != '0') {
        clear();
        show_menu(num);
        std::cin >> query;
        switch(query) {
            case '0':
                std::cout << "Bye!" << std::endl;
                break;
            case '1':
                std::cout << "Number: ";
                std::cin >> new_num;
                format(new_num);
                add(num, new_num);
                break;
            case '2':
                std::cout << "Number: ";
                std::cin >> new_num;
                format(new_num);
                sub(num, new_num);
                break;
            case '3':
                reset(num);
                break;
            default:
                std::cout << "Wrong input!" << std::endl; 
        }
    }
    return 0;
}