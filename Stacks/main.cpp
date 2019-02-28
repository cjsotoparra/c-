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
    virtual bool isEmpty () const = 0;  // return true or false
};

/////////// VectorStack //////////////
template<class T>
class VectorStack : Stack<T> {
private:
	vector<T> data;

public:

	void push (T const &el){

		data.push_back(el);

	}

	T pop(){

		T temp = data.at(data.size()-1);
		data.pop_back();
		return temp;
	}

	T top () const {
		return data.at(data.size()-1);
	}

	bool isEmpty() const{
		return data.size() == 0;
	}
};

//////////// ArrayStack //////////////
template<class T>
class ArrayStack : Stack<T> {
private:
   T data[1000];
   int count = 0;

public:

	void push (T const &el){

		data[count] = el;
		count+= 1;
	}

	T pop(){

		T temp = data[count-1];
		data[count];
		count =count -1;
		return temp;

	}

	T top() const{

		return data[count-1];
	}

	bool isEmpty() const {
		return count == 0;
	}
};

///////// LinkedStack
template<class T>
class LinkedStack : Stack<T> {
private:
	struct Node {
		T data;
		Node *next;

	Node(T const &el){
		data = el;
		next = nullptr;
	}

	};

	Node *first = nullptr;
	int n = 0;

public:

	void push (T const &el){

		if(n == 0){
			first = new Node(el);
		} else {
			Node *newNode = new Node(el);
			Node *temp = first;

			while(temp->next != nullptr){
				temp = temp->next;
			}

			temp->next = newNode;
		}

		n+= 1;
	}

	T pop () {

		Node *temp = first;
		Node *prev;

		while(temp->next != nullptr){
			prev = temp;
			temp = temp->next;
		}

		T data = temp->data;
		prev->next = nullptr;
		n+= -1;
		return data;
	}

	T top () const{

		Node *temp = first;

		while(temp->next != nullptr){
			temp = temp->next;
		}

		return temp->data;
	}

	bool isEmpty() const{
		return n == 0;
	}
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
        cout << linkedStack.top() << " ";
	linkedStack.pop();
    }

    cout << endl;

    return 0;

}

