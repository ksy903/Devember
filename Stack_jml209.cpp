/*
    prog8_main_jml209.cpp
    Stack_jml209.cpp
    Stack_jml209.h
    
    Jae Lee
    jml209
    CS 2308.01
    
    Program 8
*/

#include "Stack_jml209.h"
#include <iostream>

using namespace std;

//a destructor that will delete all dynamic data
Stack :: ~Stack(){
    CharNode *nextNode = 0,
             *cur_Node = 0;
             
    cur_Node = top;
    while(cur_Node){
        nextNode = cur_Node->next;
        delete cur_Node;
        cur_Node = nextNode;
    }
}

//push adds a new node into the stack.
void Stack :: push(char newChar){
    CharNode *new_node = new CharNode();
    new_node -> delimiter = newChar;
    if(isEmpty()){
        top = new_node;
        new_node -> next = 0;
    }
    else{
        new_node -> next = top;
        top = new_node;
    }
}

//Pop removes the top node in the stack.
char Stack :: pop(){
    CharNode *tempNode = 0;
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 'X';
    }
    else{
        char val = top -> delimiter;
        tempNode = top -> next;
        delete top;
        top = tempNode;
        return val;
    }
}

//IsEmpty simply checks if there are any elements in the Stack
bool Stack :: isEmpty() const{
    if(!top){
        return true;
    }
    else{
        return false;
    }
}

//delTypeMatches is a function that takes two delimiter chars and 
//returns a boolean based on wether they are delimiters of the same 
//pair or not.
bool Stack :: delTypeMatches(char startDel, char endDel) const{
    if((startDel == '[' && endDel == ']') 
        || (startDel == '{' && endDel == '}') 
        || (startDel == '(' && endDel == ')')){
        return true;
    }
    return false;
}
