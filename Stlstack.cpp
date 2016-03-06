/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/05/2016
** Description: Stlstack methods file which defines the methods of the
** Stlstack class that were prototyped within the Stlstack header file
*******************************************************************************/
#include <iostream>
#include <string>
#include <stack>

#include "Stlstack.hpp"

using std::cout;
using std::endl;
using std::string;
using std::stack;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Stlstack
    Function Parameters: data integer
    What the function does: adds a new stack item to the stack
*/
Stlstack::Stlstack() {
    stack<char> *newStack = new stack<char>;
    setStack(newStack);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setCurrentItem, getCurrentItem
    Functions' Parameters: setter receives data integer param for queue item
    What the functions do: getter and setter which act as public options to
                           read/write the Queue class's private queueItem
*/
void Stlstack::setStack(stack<char> *stack) {
    stlStack = stack;
}

stack<char> *Stlstack::getStack() {
    return stlStack;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: add
    Function Parameters: data integer
    What the function does: initializes a new StlstackItem struct, settings its
                            previous stack item to NULL, and its data
                            to the provided data integer.  Then gets the current
                            stack item and sets it as the current item.
*/
void Stlstack::setStackItems(string stackString) {
    stack<char> *stStack = getStack();

    for (int i = 0; i < stackString.size(); i++) {
        stStack->push(stackString.at(i));
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: remove
    Function Parameters: N/A
    What the function does: gets the current stack item and the previos item from
                            the current item, then sets the previous item as the
                            new current item, deleting the old current item and
                            returning its data integer
*/
void Stlstack::printPalindrome() {
    stack<char> *stStack = getStack();
    char stackChar[1024];
    int strLength = 0;

    while (!stStack->empty()) {
        stackChar[strLength] = stStack->top();
        strLength++;
        stStack->pop();
    }

    for (int i = strLength; i > -1; i--) {
        cout << stackChar[i];
    }

    for (int j = 0; j < strLength; j++) {
        cout << stackChar[j];
    }

    cout << endl;
}
