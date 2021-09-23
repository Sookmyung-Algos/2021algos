#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

int main() {
	int K, i, num, cnt = 0, sum = 0;
	scanf("%d", &K);
	stack<int> s; //stack s를 만들어준다
	for (i = 0; i < K; i++) {
		scanf("%d", &num);  //num을 받는다
		if (num == 0) { //num이 0이면
			s.pop();  //pop을 해주고
			cnt--;  //개수를 하나 줄인다
		}
		else {  //num이 0이 아니면
			s.push(num);  //num을 s에 push해주고
			cnt++;  //개수를 하나 늘린다
		}
			
	}
	for (i = 0; i < cnt; i++) { //개수만큼 돌기 위함이다
		int a = s.top();  //s.top()을 받아주는 변수 a
		sum += a; //sum에 a를 더한다
		s.pop();  //그리고 나서 pop으로 삭제한다
	}
	printf("%d\n", sum);
	return 0;
}
