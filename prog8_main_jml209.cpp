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
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int main(){
    cout<<"Please enter the name of the file you would like to be read or [X] to exit"<<endl;
    string input;
    cin>>input;
    ifstream inFile;
    Stack *myStack;
    bool balanced = true;
    while(input!="X" && input!="x" && balanced){
        inFile.open(input.c_str());
        if(!inFile){
            cout<<"Invalid file! Please Enter another file"<<endl;
        }
        else{
            myStack = new Stack;
            string reader;
            while(getline(inFile, reader)){
                int length = reader.length();
                for(int i=0;i<length;i++){
                    char c = reader[i];
                    if(c=='{' || c=='[' || c=='('){
                        myStack->push(c);
                    }
                    else if(c=='}' || c==']' || c==')'){
                        if(!myStack->delTypeMatches(myStack->pop(), c)){
                            balanced = false;
                        }
                    }
                }
            }
            if(!myStack->isEmpty()){
                balanced = false;
            }
            if(balanced){
               cout<<"All delimiters in "<<input<<" are balanced"<<endl;
            }
            else{
                cout<<"All delimiters in "<<input<<" are NOT balanced"<<endl;
            }
        }
        balanced = true;
        inFile.close();
        cout<<"Please enter the name of the file you would like to be read or [X] to exit"<<endl;
        cin>>input;
    }
}