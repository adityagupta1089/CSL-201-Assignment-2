#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template<typename T> class Deque {
private:
	struct DequeNode {
		DequeNode* prev;
		DequeNode* next;
		T val;
		DequeNode() :
				prev(NULL), next(NULL) {

		}
		DequeNode(const T& t, DequeNode* pPrev, DequeNode* pNext) :
				val(t), prev(pPrev), next(pNext) {
		}
	};

	DequeNode* left;
	DequeNode* right;

public:
	Deque() {
		left = new DequeNode();
		right = new DequeNode();
		left->next = right;
		right->prev = left;
	}

	bool isEmpty() const {
		return left->next == right;
	}
	void push_back(const T& t) {
		DequeNode* node = new DequeNode(t, right->prev, right);
		right->prev->next = node;
		right->prev = node;
	}
	void pop_front() {
		if (!isEmpty()) {
			DequeNode* node = left->next;
			left->next = node->next;
			node->next->prev = left;
			delete node;
		} else {
			throw runtime_error("Deque is empty");
		}
	}
	void pop_back() {
		if (!isEmpty()) {
			DequeNode* node = right->prev;
			right->prev = node->prev;
			node->prev->next = right;
			delete node;
		} else {
			throw runtime_error("Deque is empty");
		}
	}
	T front() const {
		if (!isEmpty()) {
			return left->next->val;
		} else {
			throw runtime_error("Deque is empty");
		}
	}
	T back() const {
		if (!isEmpty()) {
			return right->prev->val;
		} else {
			throw runtime_error("Deque is empty");
		}
	}
};

