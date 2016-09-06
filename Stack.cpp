#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template<typename T> class Stack {
private:
	struct StackNode {
		StackNode* prev;
		T val;
		StackNode(const T& t, StackNode* pPrev) :
				val(t), prev(pPrev) {
		}
	};

	StackNode* top;

public:
	Stack() :
			top(NULL) {
	}

	bool isEmpty() const {
		return !top;
	}
	void push(const T& t) {
		top = new StackNode(t, top);
	}

	T peek() const {
		if (!isEmpty()) {
			return top->val;
		} else {
			throw runtime_error("Stack is empty");
		}
	}

	void pop() {
		if (!isEmpty()) {
			StackNode* topNode = top;
			top = top->prev;
			delete topNode;
		} else {
			throw runtime_error("Stack is empty");
		}
	}
};

