#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int>v;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<int>ans(v); //원본벡터 복사 && 중복된 수 제거하고 정렬
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (int i = 0; i < n; i++) {
		// i번째 요소값의 위치 iterator
		auto it = lower_bound(ans.begin(), ans.end(), v[i]);
		cout << it - ans.begin() << ' '; //it에서 ans벡터의 시작 주소값을 빼준 값이 답이 됨
	}
}
