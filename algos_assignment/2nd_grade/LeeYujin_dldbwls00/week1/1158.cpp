#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, k, cnt = 0;
	queue<int> q;
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++)	q.push(i); //큐 채우기
	cout << "<";

	while (q.size() > 1) { //큐가 빌 때까지 반복
		cnt++; //큐를 순회
		if (cnt % k == 0) { //cnt의 배수일 때
			cout << q.front() + 1; //가장 앞에 있는 수 출력
			cout << ", ";
			q.pop(); //pop
		}
		else {
			q.push(q.front()); 
			q.pop(); //pop은 return값이 없으므로 마지막에 뺀다
		}
	}
	cout << q.front() + 1; //마지막 남은 값 출력
	cout << ">";
	return 0;
}
