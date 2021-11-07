// 1725 (플5) 히스토그램 
// 스택을 이용한 풀이

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int N, ans, h[100002];
stack<int> s;

int main(){

	cin >> N;

	for (int i = 1; i <= N; i++) 
		cin >> h[i];

	s.push(0); // 시작 부분 고려

	for (int i = 1; i <= N + 1; i++){	// 종료 부분 고려하기 위해 n+1까지 반복

		while (!s.empty() && h[s.top()] > h[i]){
			int temp = s.top();
			s.pop();
			ans = max(ans, h[temp] * (i - s.top() - 1));
		}
		s.push(i);
	}
	cout << ans;

}
