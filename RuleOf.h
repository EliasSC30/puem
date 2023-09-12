//
// Created by Forslund, Collin on 12.09.23.
//

#ifndef PUEM_RULEOF_H
#define PUEM_RULEOF_H


#include <iostream>
#include <cstring>

#include <memory>
#include <string>

class Person {
public:
    Person(std::string name) : name(std::make_unique<std::string>(std::move(name))) {}

    void introduce() const {
        std::cout << "Hello, my name is " << *name << std::endl;
    }

    static void example(){
        Person alice("Alice");
        alice.introduce();
    }

private:
    std::unique_ptr<std::string> name;
};

class BadString {
public:
    BadString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    ~BadString() {
        delete[] data;
    }



    const char* getData() const { return data; }

    static void ruleOfThree() {
        BadString str1("");

        {
            BadString str2("Hello");
            str1 = str2;
            std::cout << "String 1: " << str1.getData() << "\n";
            std::cout << "String 2: " << str2.getData() << "\n";

        }

        std::cout << "String 1: " << str1.getData() << "\n";
    }

    static void ruleOfFive() {
        BadString str1("");

        BadString str2("Hello");
        str1 = std::move(str2);
        std::cout << "String 1: " << str1.getData() << "\n";
        std::cout << "String 2: " << str2.getData() << "\n";
    }


private:
    char* data;
};

class GoodString {
public:
    GoodString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    ~GoodString() {
        delete[] data;
    }

    GoodString(const GoodString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    GoodString(GoodString&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }


    GoodString& operator=(const GoodString& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    GoodString& operator=(GoodString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    const char* getData() const { return data; }

    static void ruleOfThree() {
        GoodString str1("");

        {
            GoodString str2("Hello");
            str1 = str2;
            std::cout << "String 1: " << str1.getData() << "\n";
            std::cout << "String 2: " << str2.getData() << "\n";

        }

        std::cout << "String 1: " << str1.getData() << "\n";
    }

    static void ruleOfFive() {
        GoodString str1("");

        GoodString str2("Hello");
        str1 = std::move(str2);
        std::cout << "String 1: " << str1.getData() << "\n";
        // std::cout << "String 2: " << str2.getData() << "\n";
    }



private:
    char* data;
};







#endif //PUEM_RULEOF_H
