#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // 시간 초과
	int num, a, target;
	
  cin >> num;
	vector <int> v; // 벡터로 입력받기
	for (int i = 0; i < num; i++) {
		cin >> a;
		v.push_back(a);
	}
  
	cin >> target;
	sort(v.begin(), v.end()); // 정렬
	int l = 0, r = num - 1, cnt = 0;

	while (1) { // 합 확인
		if (l >= r)
			break;
		int sum = v[l] + v[r];
		if (sum == target) {
			cnt++;
			l++;
			r--;
		}
		else if (sum < target)
			l++;
		else
			r--;
	}
	cout << cnt;
	return 0;
}
