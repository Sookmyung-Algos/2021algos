#include <iostream>
#include <cstdio>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int N, K, idx;
	queue<int> Q;
	cin >> N >> K;
	int terms[500];
	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}

	printf("<");
	while (Q.size()) {
		for (idx = 1; idx < K; idx++) { //입력받은 k보다 1 작은 횟수까지 순서를 돌림.
			Q.push(q.front());
			Q.pop();
		}
		if (Q.size() == 1) {    //큐에 마지막 원소 하나가 남았을 때는 원소 출력과 괄호를 닫아주고, 반복문을 빠져나온다.
			cout << q.front();
			printf(">");
			Q.pop();
			break;
		}
		cout << Q.front();    //원소가 하나가 되기 전까지 형식에 맞춰 출력한다.
		printf(", ");
		Q.pop();
	}
	return 0;
}
