#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include "DoublyLinkedList.cpp"
#include "Stack.cpp"

using namespace std;

void print(string prefix, string postfix, DoublyLinkedNode* node, bool last) {
	cout << prefix << (last ? "└── " : "├── ") << node->val << "(" << postfix
			<< ")" << endl;
	if (node->prev) {
		print(prefix + (last ? "    " : "│   "), "left", node->prev,
				!node->next);
	}
	if (node->next) {
		print(prefix + (last ? "    " : "│   "), "right", node->next, true);
	}
}

void print(DoublyLinkedNode* node) {
	print("", "root", node, true);
}

bool is_bst(DoublyLinkedNode* bst_root) {
	Stack<DoublyLinkedNode*> s;
	map<DoublyLinkedNode*, bool> visited;
	s.push(bst_root);
	while (!s.isEmpty()) {
		DoublyLinkedNode* root = s.peek();
		s.pop();
		if (visited.find(root) != visited.end()) {
			visited[root] = true;
		} else {
			continue;
		}
		if (root
				&& ((root->next && visited.find(root->next) == visited.end())
						|| (root->prev
								&& visited.find(root->prev) == visited.end()))) {
			if (root->prev) {
				s.push(root->prev);
			}
			s.push(root);
			if (root->next) {
				s.push(root->next);
			}
		} else {
			if (!s.isEmpty() && root->val < s.peek()->val) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	size_t N;
	int min, max;
	cout << "Enter size " << endl;
	cin >> N;
	cout << "Enter minimum element" << endl;
	cin >> min;
	cout << "Enter maximum element(greater than or equal to " << min
			<< " and less than " << RAND_MAX << ")" << endl;
	cin >> max;
	DoublyLinkedList* list = new DoublyLinkedList();
	srand(time(NULL));
	for (size_t i = 0; i < N; i++) {
		int val = rand() % (max + 1 - min) + min;
		list->push_back(val);
	}
	cout << "Sorting." << endl;
	list->sort();
	cout << "Converting to BST." << endl;
	DoublyLinkedNode* root_of_bst = DoublyLinkedList::convert_to_bst(list);
	cout << "Printing BST." << endl;
	print(root_of_bst);
	cout << "Checking BST." << endl;
	int height = ceil(log2(N + 1) - 1);
	cout
			<< ((is_bst(root_of_bst)) ?
					"YES, it is a BST." : "NO, it isn't a BST.") << endl;

}
