#include <iostream>
#include <queue> //큐를 사용해야 하므로 큐 헤더 파일 include

using namespace std;

int main(int argc, const char* argv[]) {
	int N, K, cnt = 0; //N, K, 순회에 사용할 변수 선언
	cin >> N >> K; //N, K 입력 받기

	queue<int> yo; //정수형 큐 선언

	for (int i = 1; i <= N; i++) { //N명을 큐에 순서대로 넣어주기
		yo.push(i);
	}

	cout << "<"; //순열 시작을 위한 기호 출력

	while (yo.size() > 1) { //큐의 크기가 1보다 클 때(큐가 비어있지 않을 때)
		cnt++; //카운트 값 증가

		if (cnt % K == 0) { //현재 카운트 값이 K의 배수이면
			cout << yo.front() << ", "; //front 값 리턴 후
			yo.pop(); //pop 하기
		}
		else { //현재 카운트 값이 K의 배수가 아니면
			yo.push(yo.front()); //front 값을 큐에 push 해 준 뒤에
			yo.pop(); //front 값 제거
		}
	}
	cout << yo.front() << ">"; //큐에 남은 마지막 원소와 순열 마무리를 위한 기호 출력

	return 0;
}
