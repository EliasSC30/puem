#include <iostream>

void callByValue(int i){
    std::cout << "Eingabewert " << i << "\n";
    std::cout << "Erhöterwert " << ++i << "\n";
}


void callByReference(int &i){
    std::cout << "Eingabewert " << i << "\n";
    std::cout << "Erhöterwert " << ++i << "\n";
}

void callByAddress(int *i){
    std::cout << "Eingabewert " << i << "\n";
    std::cout << "Erhöterwert " << ++(*i) << "\n";
}

int main() {
    int i = 0;
    std::cout << "Call by Value:\n";
    callByValue(i);
    std::cout << "Wert nach veränderung " << i << "\n";

    std::cout << "Call by Reference:\n";
    callByReference(i);
    std::cout << "Wert nach veränderung " << i << "\n";

    std::cout << "Call by address:\n";
    callByAddress(&i);
    std::cout << "Wert nach veränderung " << i << "\n";

    return 0;
}

