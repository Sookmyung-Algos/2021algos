#include<iostream>
#include<queue>
using namespace std;
queue<int>q;
int main() {
	int N,tmp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (q.size()!=1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front()<<'\n';
	return 0;
}
