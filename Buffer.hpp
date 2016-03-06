/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/05/2016
** Description: Stack class prototype which defines the basic functionality for
** a stack, including the StackItem struct, the current stack item data member
** and its getter and setter, the constructor, and the add and remove item
** stack methods
*******************************************************************************/
#include <string>
#include <queue>

#ifndef BUFFER_HPP
#define BUFFER_HPP

using std::string;
using std::queue;

class Buffer {
 private:
    int addPercentage;
    int removePercentage;
    queue<int> *bufferQueue;
 public:
    Buffer();
    void setPercentages();
    int getAddPercentage();
    int getRemovePercentage();
    void setQueue(queue<int> *bufferQueue);
    queue<int> *getQueue();
    void attemptAdd(int queueItem);
    bool attemptRemove();
    int generateProbability();
};

#endif
