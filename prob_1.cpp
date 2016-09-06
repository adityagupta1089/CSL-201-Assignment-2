#include <iostream>
#include <fstream>
#include "Stack.cpp"
using namespace std;

bool check_ecpp(const char* filename) {
	ifstream in;
	in.open(filename);
	if (in.is_open()) {
		string line;
		Stack<char> s;
		int dollar_state = 0; //0->previous was dollar open, 1->previous was dollar close
		while (getline(in, line)) {
			for (unsigned i = 0; i < line.size(); i++) {
				char c = line.at(i);
				if (c == '{' || c == '[' || c == '(') {
					s.push(c);
				} else if (c == '$') {
					if (dollar_state == 0) {
						s.push(c);
					} else if (s.peek() != '$') {
						cout << "Didn't got $: " << c << endl;
						return false;
					} else {
						s.pop();
					}
					dollar_state = 1 - dollar_state;
				} else if (c == '}' || c == ']' || c == ')') {
					if (s.isEmpty()) {
						cout << "Empty " << endl;
						return false;
					} else if ((c == '}' && s.peek() != '{')
							|| (c == ']' && s.peek() != '[')
							|| (c == '(' && s.peek() != ')')) {
						cout << c << " doesn't match with " << s.peek() << endl;
						return false;
					} else {
						s.pop();
					}

				}
			}
		}
		return s.isEmpty();
	} else {
		cout << "Unable to open file.\n";
		return false;
	}
}

int main() {
	string filename = "./input.ecpp";
	cout << ((check_ecpp(filename.c_str())) ? "Vaild." : "Invalid.") << endl;
	return 0;
}
