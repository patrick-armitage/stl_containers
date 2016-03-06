/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/05/2016
** Description: Buffer methods file which defines the methods of the
** Buffer class that were prototyped within the Buffer header file
*******************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>

#include "Buffer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Buffer
    Function Parameters: data integer
    What the function does: adds a new stack item to the stack
*/
Buffer::Buffer() {
    queue<int> *bQueue = new queue<int>;

    setQueue(bQueue);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setCurrentItem, getCurrentItem
    Functions' Parameters: setter receives data integer param for queue item
    What the functions do: getter and setter which act as public options to
                           read/write the Queue class's private queueItem
*/
void Buffer::setPercentages() {
    int addPercent, removePercent;
    cout << "Please enter the % chance items get added to the buffer [0 .. 100]: " << endl;
    cin >> addPercent;

    while ((addPercent < 0) || (addPercent > 100)) {
        cout << "Not a valid input.  Please enter a number in the range [0 .. 100]: " << endl;
        cin >> addPercent;
    }

    cout << "Please enter the % chance items get removed from the buffer [0 .. 100]: " << endl;
    cin >> removePercent;

    while ((removePercent < 0) || (removePercent > 100)) {
        cout << "Not a valid input.  Please enter a number in the range [0 .. 100]: " << endl;
        cin >> removePercent;
    }

    addPercentage = addPercent;
    removePercentage = removePercent;
}

int Buffer::getAddPercentage() {
    return addPercentage;
}

int Buffer::getRemovePercentage() {
    return removePercentage;
}

void Buffer::setQueue(queue<int> *bQueue) {
    bufferQueue = bQueue;
}

queue<int> *Buffer::getQueue() {
    return bufferQueue;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: add
    Function Parameters: data integer
    What the function does: initializes a new BufferItem struct, settings its
                            previous stack item to NULL, and its data
                            to the provided data integer.  Then gets the current
                            stack item and sets it as the current item.
*/
void Buffer::attemptAdd(int queueItem) {
    queue<int> *bQueue = getQueue();
    int addPercent = getAddPercentage();
    int probability;

    if (addPercent > 0) {
        probability = generateProbability();
        if (probability < addPercent) {
            bQueue->push(queueItem);
            cout << "Item was added to the queue!" << endl;
        }
    }
}

bool Buffer::attemptRemove() {
    queue<int> *bQueue = getQueue();
    int removePercent = getAddPercentage();
    int probability;

    if (removePercent > 0) {
        probability = generateProbability();
        if (probability < removePercent) {
            bQueue->pop();
            cout << "Item was removed from the queue!" << endl;
            return true;
        }
    }

    return false;
}

int Buffer::generateProbability() {
    int probability = (rand() % 99) + 1;

    return probability;
}
