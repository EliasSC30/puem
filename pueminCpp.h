//
// Created by Forslund, Collin on 02.10.23.
//

#ifndef PUEM_PUEMINC_H
#define PUEM_PUEMINC_H

#include <utility>
#include <iostream>

template<class T>
void foo(T& arg){
    std::cout << "lvalue" << std::endl;
}

template<class T>
void foo(T&& arg){
    std::cout << "rvalue" << std::endl;
}

template<class T>
void wrapper(T&& arg)
{
    foo(arg);
    foo(std::forward<T>(arg));
}

void forwardExample(){
    std::cout << "Lvalue example" << std::endl;
    wrapper("lval");
    std::cout << "Rvalue example" << std::endl;
    wrapper(1);
}

#endif //PUEM_PUEMINC_H
