#include <iostream>
#include <queue> // queue헤더 포함
using namespace std;

int main() {
  // 변수 선언 
	int input, topcard;
	queue <int> q; 

	cin >> input; // 입력

	for (int i = 1; i <= input; i++) {
		q.push(i); // 큐에 1부터 input값까지 push (먼저 들어오는 게 맨 위)
	}

	while (q.size() !=1){ // size가 1이면 중단(마지막 숫자만 남음)
		q.pop(); // 맨 위 하나 제거
		topcard = q.front(); // (하나 제거된 상태에서) 맨 앞의 카드 topcard
 		q.pop(); // topcard 제거
		q.push(topcard); // 맨 아래로 topcard 붙이기
	}

	cout << q.front(); // 출력

	return 0;
}
