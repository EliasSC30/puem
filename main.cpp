#include <iostream>

#include "RVO.h"
#include "Moveable.h"


void callByValue(int i){
    std::cout << "Eingabewert " << i << "\n";
    std::cout << "Erhöhter Wert " << ++i << "\n";
}


void callByReference(int &i){
    std::cout << "Eingabewert " << i << "\n";
    std::cout << "Erhöhter Wert " << ++i << "\n";
}

void callByAddress(int *i){
    std::cout << "Eingabewert " << i << "\n";
    std::cout << "Erhöhter Wert " << ++(*i) << "\n";
}

int main() {
    /* //First
    int i = 0;
    std::cout << "Call by Value:\n";
    callByValue(i);
    std::cout << "Wert nach Veränderung " << i << "\n";

    std::cout << "Call by Reference:\n";
    callByReference(i);
    std::cout << "Wert nach Veränderung " << i << "\n";

    std::cout << "Call by address:\n";
    callByAddress(&i);
    std::cout << "Wert nach Veränderung " << i << "\n";

    auto returnValue = RVO::makeCopyElisionObservable();
    if((&returnValue == RVO::ptr)){
        std::cout << "It indeed is the same object" << std::endl;
    } else { std::cout << "Something went wrong" << std::endl; }

    RVO::showImplicitMove();*/
    Moveable::showMoveSemantics();
    return 0;
}

