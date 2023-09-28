//
// Created by Forslund, Collin on 28.09.23.
//

#ifndef PUEM_DOUBLYLINKEDLIST_H
#define PUEM_DOUBLYLINKEDLIST_H

#include <cstdint>
#include <memory>
#include <iostream>

class DoublyLinkedList {
    class Node {


    public:
        int data;
        Node* xor_ptr;

        Node(int data) : data(data), xor_ptr(nullptr) {}

        void setXOR(Node* prev, Node* next) {
            xor_ptr = reinterpret_cast<Node*>(uintptr_t(prev) ^ uintptr_t(next));
        }

        Node* getNext(Node* prev) {
            return reinterpret_cast<Node*>(uintptr_t(xor_ptr) ^ uintptr_t(prev));
        }

        Node* getPrev(Node* next) {
            return reinterpret_cast<Node*>(uintptr_t(xor_ptr) ^ uintptr_t(next));
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data) {

        Node newNode = Node(data);
        if (!head) {
            head = &newNode;
            tail = &newNode;
        } else {
            newNode.setXOR(tail, nullptr);
            tail->setXOR(tail->getPrev(nullptr), &newNode);
            tail = &newNode;
        }
    }

    void traverseForward() {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            std::cout << current->data << " ";
            Node* temp = current;
            current = current->getNext(prev);
            prev = temp;
        }
        std::cout << std::endl;
    }

    void traverseBackward() {
        Node* current = tail;
        Node* next = nullptr;
        while (current) {
            std::cout << current->data << " ";
            Node* temp = current;
            current = current->getPrev(next);
            next = temp;
        }
        std::cout << std::endl;
    }

    static void showDoublyLinkedList(){
        DoublyLinkedList myList;

        myList.append(1);
        myList.append(2);
        myList.append(3);
        myList.append(4);
        myList.append(5);

        std::cout << "Forward traversal: ";
        myList.traverseForward();

        std::cout << "Backward traversal: ";
        myList.traverseBackward();
    }
};



#endif //PUEM_DOUBLYLINKEDLIST_H
