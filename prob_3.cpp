#include <iostream>
#include "Deque.cpp"
#include <vector>
#include <sstream>

using namespace std;

int main() {
	Deque<size_t> min_index_deck;
	Deque<size_t> max_index_deck;
	size_t n, k;
	cout << "Enter Size." << endl;
	cin >> n;
	int a[n];
	vector<pair<int, int> > range_vector;
	cout << "Enter SubArray Size." << endl;
	cin >> k;
	cout << "Enter Elements" << endl;
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
	stringstream output;
	output << "[";
	for (size_t i = 0; i <= sizeof(a) / sizeof(int); i++) {
		if (i >= k) {
			range_vector.push_back(
					make_pair(a[min_index_deck.front()],
							a[max_index_deck.front()]));
			while (!max_index_deck.isEmpty() && max_index_deck.front() <= i - k) {
				max_index_deck.pop_front();
			}
			while (!min_index_deck.isEmpty() && min_index_deck.front() <= i - k) {
				min_index_deck.pop_front();
			}
		}
		while (!max_index_deck.isEmpty() && a[max_index_deck.back()] <= a[i]) {
			max_index_deck.pop_back();
		}
		while (!min_index_deck.isEmpty() && a[min_index_deck.back()] >= a[i]) {
			min_index_deck.pop_back();
		}
		min_index_deck.push_back(i);
		max_index_deck.push_back(i);
	}
	cout << "The range vector is: " << endl;
	for (size_t i = 0; i <= n - k; i++) {
		output << "(" << range_vector[i].first << "," << range_vector[i].second
				<< ")" << ((i != n - k) ? ", " : "]\n");
	}
	cout << output.str();
}
