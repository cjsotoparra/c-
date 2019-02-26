#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

// Stack is an abstract class because it has all pure virtual
// functions.  This is the eqiivalent to the Java interface
template<typename Type>
class Stack {
public:
    virtual void push (Type const &) = 0; // push element
    virtual Type pop () = 0; // return top element & remove
    virtual Type top () const = 0;      // return top el
    virtual bool isEmpty () const = 0;  // return true
};

/*
/////////// VectorStack //////////////
template<class T>
class VectorStack : Stack<T> {
    // You will get many errors until this implements the
    // four methods or you comment out this class
};



//////////// ArrayStack //////////////
template<class T>
class ArrayStack : Stack<T> {
private:
   T data[1000];

    // You will get many errors until this implements the
    // four methods or you comment out this class
};



///////// LinkedStack
template<class T>
class LinkedStack : Stack<T> {
    // You will get many errors until this implements the
    // four methods or you comment out this class
};


// You will get many errors until all three classes are
// implemented. Consider commenting out code and completing
// one class at a time

int main () {

    // Show VectorStack<T>
    VectorStack<int> intStack;  // stack of ints
    VectorStack<string> stringStack;    // stack of strings

    // manipulate int stack
    intStack.push(7);
    cout << intStack.top() << endl;

    // manipulate string stack
    stringStack.push("hello");
    stringStack.push("goodbye");
    cout << "StringStack top: " << stringStack.top()
         << std::endl;
    cout << stringStack.pop() << endl;
    cout << stringStack.pop() << endl;
    cout << endl;

    return 0;
}
/*
    // Show ArrayStack<T>
    ArrayStack<int> arrayStack;
    arrayStack.push(1);
    arrayStack.push(2);
    arrayStack.push(3);
    arrayStack.push(4);
    cout << "ArrayStack top: " << arrayStack.top() << endl;
    while(! arrayStack.isEmpty()) {
        cout << arrayStack.pop() << " ";
    }
    cout << endl;
    cout << endl;

    // Show LinkedStack<T>
    LinkedStack<int> linkedStack;
    linkedStack.push(1);
    linkedStack.push(2);
    linkedStack.push(3);
    linkedStack.push(4);
    cout << "LinkedStack top: " << linkedStack.top() << endl;
    while(! linkedStack.isEmpty()) {
        cout << linkedStack.pop() << " ";
    }

}
*/
