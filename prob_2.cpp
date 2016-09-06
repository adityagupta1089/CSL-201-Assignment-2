#include <iostream>
#include "Stack.cpp"

using namespace std;

int main() {
	size_t n;
	cout << "Enter Size." << endl;
	cin >> n;
	int a[n];
	cout << "Enter Elements" << endl;
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	Stack<int> s;
	for (size_t i = 0; i < n; i++) {
		while (!s.isEmpty() && a[i] > s.peek()) {
			s.pop();
		}
		if (s.isEmpty()) {
			cout << "-1";
		} else {
			cout << s.peek();
		}
		cout << ((i == n - 1) ? "\n" : ", ");
		s.push(a[i]);
	}
}
