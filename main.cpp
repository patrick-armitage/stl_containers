#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include "Stlstack.hpp"
#include "Buffer.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

int getSelection();
int getAverage(int numerator, int denominator);

int main() {
    Stlstack *stStack = new Stlstack;
    string pStr;

    Buffer *stBuffer = new Buffer;
    int numAttempts;
    double average = 0.0, numAttempted = 0.0, rollingTotal = 0.0, numRemoved = 0.0;
    bool wasRemoved = false;

    int sel;
    sel = getSelection();
    while ((sel != 1) && (sel != 2)) {
        cout << "Whoops!  That isn't a valid selection.  Please try again." << endl;
        getSelection();
    }

    if (sel == 1) {
        cout << "Please input a string you wish to turn into a palindrome: ";
        cin >> pStr;

        stStack->setStackItems(pStr);

        cout << "Thank you!  You have entered '" << pStr << "'!" << endl;
        cout << "Your palindrome is: ";
        stStack->printPalindrome();
    } else if (sel == 2) {
        cout << "Please enter the number of attempts you wish to make to add items ";
        cout << "to the buffer, then remove them: ";
        cin >> numAttempts;

        stBuffer->setPercentages();

        for (int i = 0; i < numAttempts; i++) {
            cout << "Adding attempt number " << (i + 1) << ":" << endl;
            stBuffer->attemptAdd(i);
            numAttempted += 1.0;
            rollingTotal += static_cast<double>(stBuffer->getQueue()->size());
            if (stBuffer->getQueue()->size() > 0) {
                average = rollingTotal / numAttempted;
            }
            cout << "There are currently " << stBuffer->getQueue()->size();
            cout << " items in the queue" << endl;
            cout << "Average number of items added to queue: ";
            cout << fixed << setprecision(1) << average << endl << endl;
        }

        numAttempted = 0.0;
        for (int i = 1; i < numAttempts; i++) {
            cout << "Removal attempt number " << i << ":" << endl;
            wasRemoved = stBuffer->attemptRemove();
            if (wasRemoved == true) {
                numRemoved += 1.0;
            }
            if (stBuffer->getQueue()->size() > 0) {
                average = numRemoved / static_cast<double>(i);
            } else {
                cout << "There are no longer any items in the queue!" << endl;
                break;
            }

            cout << "There are currently " << stBuffer->getQueue()->size();
            cout << " items in the queue" << endl;
            cout << "So far, " << fixed << setprecision(1) << numRemoved;
            cout << " have been removed from the queue" << endl;
            cout << "Average number of items removed from the queue is: ";
            cout << fixed << setprecision(1) << average << endl << endl;
        }
    }
    return 0;
}

int getSelection() {
    int selection;
    cout << "Welcome to STL Stack and Queue Demos.  Please select a demo:" << endl;
    cout << "[1] STL Stack, [2] STL Queue" << endl;
    cin >> selection;

    return selection;
}
