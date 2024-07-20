// test for push, empty, size, pop, and top methods of a stack

#include <iostream>
#include <stack> 

using namespace std;

int main(){
    stack<int> newStack;

    newStack.push(3);
    newStack.push(2);
    newStack.push(12);
    
    cout << "Stack Empty? " << newStack.empty() << "\n";
    cout << "Stack Size: " << newStack.size() << "\n";
    cout << "Top Element: " << newStack.top() << "\n";

    newStack.pop();
    cout << "Top Element after pop: " << newStack.top() << "\n";
    cout << "Stack Size: " << newStack.size() << "\n";
}