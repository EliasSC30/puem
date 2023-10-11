#ifndef PUEM_CALLBY_H
#define PUEM_CALLBY_H
#include <iostream>

class CallBy {
public:
    static void callByValue(int i){
        std::cout << "Eingabewert " << i << "\n";
        std::cout << "Erhöhter Wert " << ++i << "\n";
    }


    static void callByReference(int &i){
        std::cout << "Eingabewert " << i << "\n";
        std::cout << "Erhöhter Wert " << ++i << "\n";
    }

    static void callByAddress(int *i){
        std::cout << "Eingabewert " << i << "\n";
        std::cout << "Erhöhter Wert " << ++(*i) << "\n";
    }

    static void showCallBys(){
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
    }

};


#endif //PUEM_CALLBY_H
