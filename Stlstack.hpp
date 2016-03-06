/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/05/2016
** Description: Stack class prototype which defines the basic functionality for
** a stack, including the StackItem struct, the current stack item data member
** and its getter and setter, the constructor, and the add and remove item
** stack methods
*******************************************************************************/
#include <string>
#include <stack>

#ifndef STLSTACK_HPP
#define STLSTACK_HPP

using std::string;
using std::stack;

class Stlstack {
 private:
    stack<char> *stlStack;
 public:
    Stlstack();
    void setStack(stack<char> *stlStack);
    stack<char> *getStack();
    void setStackItems(string stackString);
    void printPalindrome();
};

#endif
