#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);  //시간초과로 인해 시간단축을 위해 사용
	vector <int> v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		v.push_back(c);  //벡터에 들어갈 값입력받기
	}
	sort(v.begin(), v.end());  //정렬
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		cout << upper_bound(v.begin(), v.end(), k) - lower_bound(v.begin(), v.end(), k) << " "; //카드의 개수 출력
	}
}
