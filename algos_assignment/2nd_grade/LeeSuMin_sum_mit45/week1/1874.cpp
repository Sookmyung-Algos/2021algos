/////////////////////////////////////////////
//작성날짜: 2021.04.07
//문제: 백준 1874) 스택 수열 
//기타: stack 사용 예제
/////////////////////////////////////////////

#include <stack>
#include <iostream>
using namespace std;

int main() {

	//fast I/O
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	char sol[200050];
	int solptr(0);
	int n,x, max(0);  
	cin >> n; // 입력 첫 줄

	stack<int> s; //정수형 stack 생성

	while (n--) {
		cin >> x; // 임의의 수열 입력
		if (x > max) { // max보다 크다면 
			for (int i = max + 1; i <= x; i++) { //i=1부터 x까지
				s.push(i); //i추가
				sol[solptr++] = '+'; //push되는 만큼 +출력
			}
		}
		else { // max보다 작다면
			if (s.top() != x) { //max다음부터는 내림차순이여야만 구현 가능
				cout << "NO";
				return 0; //while문 나오기
			}
		}
		s.pop(); // max보다 작고 s,top
		sol[solptr++] = '-';
		if (max < x) //max값으로 정하기
			max = x; 
	}

	for (int i = 0; i < solptr; i++) {
		cout << sol[i] << '\n';
	}

	return 0;
}
