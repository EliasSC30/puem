//
// Created by Oezcan, Elias on 27.09.23.
//

#ifndef PUEM_STACK_H
#define PUEM_STACK_H
#include <iostream>
#include <vector>

class Stack {
public:
    static std::vector<int> thirdWithBoth(std::vector<int> v){
        v.erase(std::remove_if(v.begin(), v.end(), [](int a){ return (a % 2 == 0); }), v.end());
        return v;
    }

    static void sndWithoutParams(){
        std::vector<int> numbers = {0,1,2,3,4,5,6,7,8,9};
        std::vector<int> oddNumbers = thirdWithBoth(numbers);
    }

    static void firstWithoutLocals(){
        sndWithoutParams();
    }

    static void showStackFrames() {
        firstWithoutLocals();
    }
};


#endif //PUEM_STACK_H
