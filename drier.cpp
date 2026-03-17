#include <iostream>
#include "StackFactory.hpp"

int main()
{
    Stack<int> * mystack = StackFactory<int>::GetStack();
    mystack->push(1);
    mystack->push(2);
    mystack->push(3);
    mystack->push(4);
    mystack->push(5);
    cout << mystack->peek() << "\n";
    mystack->pop();
    mystack->pop();
    mystack->pop();
    mystack->push(6);
    mystack->rotate(Stack<int>::Direction::RIGHT);
    mystack->push(7);
    cout << mystack->getLength();

    Stack<string> * shouldCreateArraystack = StackFactory<string>::GetStack(5);
    shouldCreateArraystack->push("one");
    shouldCreateArraystack->push("two");
    shouldCreateArraystack->push("three");
    shouldCreateArraystack->push("four");
    shouldCreateArraystack->push("five");
    //cout << shouldCreateArraystack->peek() << "\n";
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->push("six");
    shouldCreateArraystack->rotate(Stack<string>::Direction::LEFT);
    shouldCreateArraystack->push("seven");
    cout << " " << shouldCreateArraystack->getLength();


}