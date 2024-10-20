#ifndef TEMPLATESTACK_H_INCLUDED
#define TEMPLATESTACK_H_INCLUDED
#include "TemplateTest.cpp"
#include <iostream>

//Constructors
template <class T> class Node{

public:


    T data;
    Node<T>* next;

    Node(T data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(T data1){
        data = data1;
        next = nullptr;
    }


};

//stack data structure of type string
template <class T> class TemplateStack{

    private:
    //Stores head element
    Node<T>* head;

    public:
    //overloaded constructor of type StringStack

    TemplateStack(){
     head = nullptr;
    }

    TemplateStack(T data1){
     head = new Node<T>(data1);
    }

    TemplateStack(T data1, Node<T>* next1){
     head = new Node<T>(data1, next1);
    }

    //stringStack functions
    //returns the top element
    void PeekTStack(){
        if(!IsEmpty()) std::cout << head->data;
        else std::cout << "empty";
    }

    //checks if stack is empty
    bool IsEmpty(){
     if (head == nullptr) return true;
     else return false;
    }

    //removes and outputs the first element returns 0 if empty
    T PopStack(){
        if(!IsEmpty()) {
            Node<T>* temp = head;
            head = head->next;
            return temp->data;
        }
        else {

                std::cout << "error\n";
                return 0;
        }
    }

    //adds element of type string to stack
    void PushStack(T data1){
        Node<T>* temp = head;
        head = new Node<T>(data1, temp);
    }

    //return numbers of elements in set(int)
    int ElementsInStack(){
        if(IsEmpty()) return 0;

        int counter = 0;
        Node<T>* temp = head;
        while(temp->next != NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    //outputs all string to console
    void ShowStack(){

        if(IsEmpty())
            std::cout << "empty" << std::endl;

        Node<T>* temp = head;
        while(temp->next != nullptr){
            if (temp->next->next == nullptr) break;
            std::cout << temp ->data << ", ";
            temp = temp->next;
        }
        std::cout << temp ->data << "\n";

    }



};

#endif // TEMPLATESTACK_H_INCLUDED
