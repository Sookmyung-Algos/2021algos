#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
queue<int> result;
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) q.push(i);
	
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		result.push(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i < N - 1) cout << result.front() << ", ";
		else cout << result.front();
		result.pop();
	}
	cout << ">";

	return 0;
}
