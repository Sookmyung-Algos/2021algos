#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
	int N, k, i, cnt = 0;
	scanf("%d %d", &N, &k); //N과 k 받아주기
	queue<int> q; //queue q 만들어주기
	for (i = 1; i <= N; i++) {  //q에 값 넣어주는 과정
		q.push(i);
	}
	printf("<");
	while (q.size() > 1) {  //마지막은 숫자>로 끝나야 하기 때문에 1을 초과하는 순간까지 해준다.
		cnt++;
		if (cnt % k == 0) { //순서가 k의 배수일 때
			printf("%d, ", q.front());  //print를 해준다
			q.pop();
		}
		else {
			int a = q.front();  //a라는 q.front()를 받아줄 변수 만들기
			q.push(a);  //a를 뒤에 push
			q.pop();  //q.front() 없애주기
		}
	}
	printf("%d>", q.front()); //마지막 숫자 print해주기
	return 0;
}
