#include<iostream>
#include<queque>

using namespace std;

int main() {
	int n, k;
	queue<int> q;//큐 q 생성

	cin >> n >> k;//
	cout << "<";

	for (int i = 1; i <= n; i++) {
		q.push(i);//n명의 사람, 1부터 n까지 수를 모두 q에 넣는다.
	}
	while (!q.empty()) {
		for (int j = 0; j < k-1; j++) {
			q.push(q.front);//q의 가장 앞에 있는 원소를 뒷쪽에 추가한 후
			q.pop();//q의 가장 앞에 있는 원소를 빼내어 k가 아닌 수를 제거하지 않으면서 동시에 k가 q의 가장 앞에 오도록 만든다.
		}
		cout << q.front();//k 출력

		q.pop();
		if (!q.empty())
			cout << ","; //k를 pop()했을 때 q에 남은 수가 있다면 while문을 반복해 요세푸스 순열을 완성한다.
	}
	cout << ">";
	return 0;
}
