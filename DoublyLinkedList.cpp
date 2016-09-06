#include <iostream>
#include <cstdlib>

using namespace std;

class DoublyLinkedNode {
public:
	DoublyLinkedNode* next;
	DoublyLinkedNode* prev;
	int val;
	friend class DoublyLinkedList;
};
class DoublyLinkedList {
private:
	int size;
	DoublyLinkedNode* header;
	DoublyLinkedNode* trailer;
	DoublyLinkedNode* remove(DoublyLinkedNode* n1) {
		n1->prev->next = n1->next;
		n1->next->prev = n1->prev;
		return n1;
		size--;
	}
	void push_before(DoublyLinkedNode* n1, DoublyLinkedNode* n2) {
		n1->prev->next = n2;
		n2->prev = n1->prev;
		n2->next = n1;
		n1->prev = n2;
	}
	static DoublyLinkedNode* convert_to_bst(DoublyLinkedNode* start,
			DoublyLinkedNode* finish) {
		if (start == finish) {
			start->next = NULL;
			start->prev = NULL;
			return start;
		}
		DoublyLinkedNode* n1 = start, *n2 = finish;
		while (n1 && n2 && n1->next != n2) {
			n1 = n1->next;
			if (n1->next == n2)
				break;
			n2 = n2->prev;
			if (n1->next == n2)
				break;
		}
		if (!n1 || !n2) {
			return NULL;
		}
		n1->prev = convert_to_bst(start, n1->prev);
		n1->next = convert_to_bst(n1->next, finish);
		return n1;
	}
public:
	DoublyLinkedList() {
		header = new DoublyLinkedNode;
		trailer = new DoublyLinkedNode;
		header->next = trailer;
		trailer->prev = header;
		size = 0;
	}
	void push_back(int& t) {
		DoublyLinkedNode* p = new DoublyLinkedNode;
		p->val = t;
		push_before(trailer, p);
		size++;
	}
	void sort() {
		for (DoublyLinkedNode* first = header->next->next; first != trailer;
				first = first->next) {
			DoublyLinkedNode* second = first;
			while (second != header->next && second->prev->val > first->val)
				second = second->prev;
			if (second->val > first->val) {
				DoublyLinkedNode* first_next = first->next;
				DoublyLinkedNode* floating_first = remove(first);
				push_before(second, floating_first);
				first = first_next->prev;
			}
		}
	}
	static DoublyLinkedNode* convert_to_bst(DoublyLinkedList* list) {
		return convert_to_bst(list->header->next, list->trailer->prev);
	}
};
