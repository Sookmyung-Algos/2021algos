#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	
	int n; 
	cin >> n;
	deque<int> q;
	vector<int> vect(n + 1);
	for (int i = 0; i < n; i++) q.push_back(i);
	for (int i = 0; i < n; i++) cin >> vect[i];
	while (n--) {
		int front = vect[q.front()];
		cout << q.front() << " "; q.pop_front();
		if (q.empty()) break;
		if (front > 0) {
			while (--front) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else {
			while (front++) {
				q.push_front(q.back());
				q.pop_back();
			}
		}
	}
}
