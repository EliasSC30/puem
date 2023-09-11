//
// Created by Oezcan, Elias on 11.09.23.
//

#ifndef PUEM_RVO_H
#define PUEM_RVO_H

#include <vector>
#include <string>
#include <iostream>

int light(){
    int x{};
    //some calculations..
    return x;
}

std::vector<std::string> heavy(){
    std::vector<std::string> names{};
    for(int i{0}; i < 1000; ++i){
        names.emplace_back("Name");
    }

    return names;
}



class RVO {
public:
    class Observable{
        std::vector<std::string> names{};
    public:

        Observable(){
            std::cout << "Observable was constructed" << std::endl;

        }
        Observable(const Observable& other){
            std::cout << "Observable got copy-constructed" << std::endl;
        }
        Observable(Observable&& other){
            std::cout << "Observable got move constructed" << std::endl;
        }

        ~Observable(){
            std::cout << "Deleted Observable" << std::endl;
        }
    };

    inline static Observable* ptr{};

    static Observable makeCopyElisionObservable(){
        Observable o{};
        ptr = &o;
        return o;
    }

    static void showCopyElision(){
        auto returnValue = makeCopyElisionObservable();
        if((&returnValue == ptr)){
            std::cout << "It indeed is the same object" << std::endl;
        } else { std::cout << "Something went wrong" << std::endl; }
    }

    static Observable showImplicitMove(){
        Observable o;
        Observable u;
        int runTimeDecision{};
        std::cout << "Make a decision\n";
        std::cin >> runTimeDecision;
        return runTimeDecision > 2 ? u :o;
    }

};


#endif //PUEM_RVO_H
