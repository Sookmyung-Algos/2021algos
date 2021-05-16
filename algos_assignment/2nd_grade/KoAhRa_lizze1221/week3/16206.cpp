#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
	int n, m, a, ans = 0 , temp;
	cin >> n >> m;
	vector <int> v;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 10) { // a가 10인 경우는
			ans++;
			continue; // 자르는 것을 고려하지 않아도 된다.
		}
		if (a > 10) {
			v.push_back(a); 
		}
	}
	sort(v.begin(), v.end());

	if (v.size() == 0) { // size가 0이라면
		cout << ans; // ans 출력하고 종료
		return 0;
	}

	for (int i = 0; i < v.size(); i++) {
		if (m < 1)break; // 자를 횟수가 없으면 종료
		if (v[i] % 10 != 0)continue; // 10의 배수가 아니라면 계속
		if (v[i] == 20) { // 한 번 자르면 2개 만들 수 있다.
			v[i] = 0;
			m -= 1; // 자른 횟수 1번 사용
			ans += 2; // ans에 2 더해주기
		}
		else if (v[i] / 10 - 1 <= m) { 
			temp = v[i] / 10 - 1;
			v[i] = 0;
			m -= temp;
			ans += (temp + 1);
		}
		else {
			temp = m;
			v[i] = 0;
			m -= temp;
			ans += temp;
		}

	}
	// 위의 for문을 끝내면 처리된 값은 0이 된다.
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) continue; 
		if (m < 1) continue;

		if (v[i] / 10 > m) { // 만약 10으로 나눈 몫이 남은 횟수보다 많으면
			temp = m;
			v[i] = 0; // 그 값 0으로 만들어서 처리해주고
			m -= temp;
			ans += temp; // 그 자른 횟수만큼 ans 더해주기
		}
		else {
			temp = v[i]/10;
			v[i] = 0;
			m -= temp;
			ans += temp;
		}
	}
	cout << ans; // 마지막에 ans 출력
	return 0;
}
