/*
 * LinkedPriorityList.cpp
 *
 *  Created on: March 8, 2019
 *      Author: Rick Mercer and Christian Soto
 *
 * This class represents one implementation of the abstract
 * base class PriorityList. Like any container, there
 * are insert and remove functions. Indexes represent
 * priorities and the priorities can change in several ways.
 * The element at index 0 has the highest priority.
 * The element at size()-1 has the lowest priority.
 */
#include "PriorityList.h"
#include <stdexcept> // for std::invalid_argument(string)
#include <memory>    // for std::shared_ptr<T>
#include <string>    // for std::to_string

template<typename Type>
class LinkedPriorityList: public PriorityList<Type> {

private:
  struct Node {
    Type data;
    std::shared_ptr<Node> next;

    // You may not need this Node constructor
    explicit Node(Type element) {
      data = element;
      next = nullptr;
    }

    Node(Type element, std::shared_ptr<Node> nextRef) {
      data = element;
      next = nextRef;
    }
  };

  std::shared_ptr<Node> first;
  int n;

public:

	// Create an empty list with zero elements
	LinkedPriorityList() {
		first = nullptr;
		n = 0;
	}

  // Add all functions found in PriorityList.h except
  // ~PriorityList. Consider copying the function headings
  // and comments from PriorityList.h. Remove virtuals
  // and = 0;.  Replace ;s with a function body.


	int size() const override {
		return n;
	}//size

	bool isEmpty() const override{
		return n == 0;
	}//isEmpty

	Type getElementAt(int index) const override{

		if(index < 0 || index >=size()){

			throw std::invalid_argument("recieved invalid index");

		}else{

			auto i{0};

			std::shared_ptr<Node> temp = first;

			while(i<index){

				temp = temp->next;
				i++;
			}

			return temp->data;
		}

	}//getElementAt

	void insertElementAt(int index, const Type &el) override{

		if(index < 0){

			throw std::invalid_argument("Index cannot be less than 0");
		}

		if(index > size() && isEmpty()){

			throw std::invalid_argument("List is empty, index must be 0");
		}

		if(index > size() && !isEmpty()){

			throw std::invalid_argument("Index must be less than size()+1");
		}

		//list is empty
		if(index == 0 && isEmpty()){

			first = std::shared_ptr<Node>(new Node(el, nullptr));
			n += 1;
			return;
		}

		std::shared_ptr<Node> new_node = std::shared_ptr<Node>(new Node(el));

                //insert at the beginning of the list
                if(index == 0 && !isEmpty()){

			new_node->next = first;
			first = new_node;
			n += 1;
			return;
                }

		std::shared_ptr<Node> temp = first;
		std::shared_ptr<Node> prev;

		auto i{0};

		while(i<=index-1){
			prev = temp;
			temp = temp->next;
			i++;
		}

		prev->next = new_node;
		new_node->next = temp;
		n += 1;

	}//insertElementAt

	void removeElementAt(int index){

		if(isEmpty()){

			throw std::invalid_argument("can't remove from an empty list");

		}else if(index < 0 || index >= size()){

			throw std::invalid_argument("Invalid index");

		//remove head
		}else if(index == 0){

			std::shared_ptr<Node> temp = first;

			//move first ptr to next
			first = first->next;
			temp = nullptr;
			n += -1;
			return;
		}else {


			std::shared_ptr<Node> temp = first;
			std::shared_ptr<Node> prev;

			auto i{0};

			while(i<=index-1){

				prev = temp;
				temp = temp->next;
				i++;
			}

			prev->next = temp->next;
			temp = nullptr;

			n += -1;
			return;
		}//if else statement

	}//removalElement

	void lowerPriorityOf(int index){

		if(index == size()-1){

			return;
		}

		if(size() == 1){

			return;
		}

		if(index < 0 || index >= size()){

			throw std::invalid_argument("invalid index given");
		}

		Type tdata;
		std::shared_ptr<Node> temp = first;

		if(index == 0){

			tdata = first->data;
			first->data = temp->next->data;
			temp->next->data = tdata;
			return;
		}

		std::shared_ptr<Node> prev;
		auto i{0};

		while(i <= index){

			prev = temp;
			temp = temp->next;
			i++;
		}

		tdata = prev->data;
		prev->data = temp->data;
		temp->data = tdata;
		return;

	}//lowerPriorityOf

	void raisePriorityOf(int index){

		if(index == 0 || size() == 1){

			return;
		}

		if(index < 0 || index >= size()){

			throw std::invalid_argument("invalid argument");
		}

		Type tData;
		std::shared_ptr<Node> temp = first;
		std::shared_ptr<Node> prev;
		auto i{0};

		while(i <= index-1){

			prev = temp;
			temp = temp->next;
			i++;
		}

		tData = temp->data;
		temp->data = prev->data;
		prev->data = tData;

		return;
	}//raisePriorityOf

	void moveToLast(int index){

		if(index == size()-1 || size() ==1){
			return;
		}

		if(index < 0 || index >= size()){
			throw std::invalid_argument("invalid argument");
		}

		Type tData = getElementAt(index); //save element
		removeElementAt(index); // remove index, size() is now size()-1

		insertElementAt(size(), tData);
		return;
	}

	void moveToTop(int index){

		if(index == 0 || size() ==1){
			return;
		}

		if(index < 0 || index >= size()){

			throw std::invalid_argument("invalid argument");
		}

		Type tData = getElementAt(index);
		removeElementAt(index);
		insertElementAt(0, tData);
		return;
	}
};
