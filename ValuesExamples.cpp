#include <iostream>


void bar(){
    class A{
    public:
        int age{};
    };
    A a;
    A&& rValRef = std::move(a);

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
}