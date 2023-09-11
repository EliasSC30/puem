//
// Created by Oezcan, Elias on 11.09.23.
//

#ifndef PUEM_MOVEABLE_H
#define PUEM_MOVEABLE_H
#include <iostream>

class Moveable {
public:
    Moveable(){
        std::cout << "Constructed Moveable" << std::endl;
    }
    Moveable(const Moveable& other) {
        std::cout << "Copy-constructed Moveable" << std::endl;
    }
    ~Moveable(){
        std::cout << "Destructed Moveable" << std::endl;
    }
    Moveable& operator=(const Moveable& other){
        std::cout << "Assigned Moveable" << std::endl;
        return *this;
    }

    //Move constructor
    Moveable(Moveable&& rVal) noexcept {
        std::cout << "Move-constructed Moveable" << std::endl;
    }
    //Move assignment operator
    Moveable& operator=(Moveable&& rVal) noexcept {
        std::cout << "Move-assigned Moveable" << std::endl;
        return *this;
    }

    static void showMoveSemantics() {
        //Construction
        Moveable m{};
        //Copy-construction
        Moveable n = m;
        //Assignment
        n = m;
        //move construction: m is now 'will-be moved'
        Moveable o = std::move(m);
        //move assignment: n is now 'will-be moved'
        o = std::move(n);
    }

};


#endif //PUEM_MOVEABLE_H
