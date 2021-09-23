#include <iostream>
#include <queue>

using namespace std;


int main() {
	int N, K;
	cin >> N >> K;

	queue <int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i); // 1부터 N까지의 숫자 push
	}

	cout << "<";

	for (int j = 0; j < N - 1; j++) {
		for (int k = 0; k < K - 1; k++) {
			q.push(q.front()); // 맨 앞에 있는 값을 뒤로 옮기고
			q.pop(); // 그 값은 pop하기
		}
		cout << q.front()<<", "; // for문 빠져나오면 그 앞에 있는 값 출력하고
		q.pop(); // 출력한 값은 pop하기
	}
	cout << q.front() << ">\n";
	return 0;
}
