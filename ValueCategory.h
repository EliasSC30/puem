//
// Created by Oezcan, Elias on 11.09.23.
//

#ifndef PUEM_VALUECATEGORY_H
#define PUEM_VALUECATEGORY_H
#include <iostream>

class A {
public:
    int age{};
};

void fu(A& aRef){
    std::cout << "Called the reference method" << std::endl;
}
void fu(A&& aRValRef){
    std::cout << "Called the && method" << std::endl;
}

void bar(){

    A a;
    A&& rValRef = std::move(a);
    fu(rValRef);
    //1:example lvalue
    a;

    //2.example xvalue thats a glvalue
    rValRef;

    //xvalue thats an rvalue
    std::move(a);

    //prvalue
    4;

    //Quiz
    //1.
    "Thats some text";
    //2.
    ++a.age;
    //3.
    a.age++;

    //4.What will compile?
    int x{};

    // l-value references
    //int& ref1{ x }; // A
    //int& ref2{ 5 }; // B

    //const int& ref3{ x }; // C
    //const int& ref4{ 5 }; // D

    // r-value references
    //int&& ref5{ x }; // E
    //int&& ref6{ 5 }; // F

    //const int&& ref7{ x }; // G
    //const int&& ref8{ 5 }; // H
}

class ValueCategory {

};


#endif //PUEM_VALUECATEGORY_H
