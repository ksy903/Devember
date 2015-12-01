/*
    prog8_main_jml209.cpp
    Stack_jml209.cpp
    Stack_jml209.h
    
    Jae Lee
    jml209
    CS 2308.01
    
    Program 8
*/

#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack{
    private:
        struct CharNode{
            char delimiter;
            CharNode *next;
        };
        CharNode *top;
    public:
        Stack(){
            top = 0;
        }
        ~Stack();
        void push(char newChar);
        char pop();
        bool isEmpty() const;
        bool delTypeMatches(char startDel, char endDel) const;
};

#endif