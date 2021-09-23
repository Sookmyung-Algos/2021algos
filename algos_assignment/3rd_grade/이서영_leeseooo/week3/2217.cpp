#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int main() {
	int n, k;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end(),greater<int>()); //내림차순 정렬
	//가장 무거운 로프가 가장 큰 중량을 들 수 있다.
	//가벼운 로프일수록 로프 개수가 많이 필요하다.

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i] * (i + 1));//가장 큰 무게를 들 수 있는 로프 = 현재 로프의 무게 * 로프의 개수
	}
	cout << ans;
}
