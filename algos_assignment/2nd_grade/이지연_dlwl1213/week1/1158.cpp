#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int N, K; //사람의 수를 입력받을 N과 제거할 기준이 되는 수 K를 정수형 변수로 선언
	queue <int> q;  // 사람 수를 넣고 순회를 통해 순열을 구하기 위한 q라는 이름의 큐를 선언

	cin >> N >> K;  // 첫째 줄에 N,K를 입력받음
	cout << "<";  // 출력할 요세푸스 순열을 예제의 형식과 같게하기 위해 <를 먼저 출력해줌

	for (int i = 0; i < N; i++) {  // N명의 사람을 q에 넣어줌(사람은 1~N까지)
		q.push(i+1);
	}
	while (!q.empty()) {  // 모든 사람이 제거되기 전까지 반복해주기 위한 조건으로 q가 empty가 아님을 넣어줌
		for (int j = 0; j < K - 1; j++) {  //K번째 사람을 제거해주기 위한 for문
			q.push(q.front());   //k번째가 아니라면 큐의 가장 앞에있는 원소를 맨 뒤에 push 해준 다음->
			q.pop();   //앞에 있던 원소를 pop해줌(->for문의 조건이 만족된다면 이 과정이 반복됨)
		}
		cout << q.front();   //for문의 조건을 벗어나게 되면 즉, k번째가 되면 k번째 사람(현재 q에서 가장 앞에 있는 사람에 해당)을 출력하고->
		q.pop();             //큐에서 제거해줌
		if (!q.empty())  //아직 사람이 큐에 남아있다면 while문이 반복됨
			cout << ", ";   //다음 사람을 출력하기 전에 ,를 출력해주어 예제 형식에 맞도록 함 
	}
	cout << ">";  //요세푸스 순열이 while문에 의해 모두 출력되면 >를 출력해 출력 마무리
	return 0;
}
