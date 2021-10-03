#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
vector <int> v1, v2;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c1, c2;
	int x, cnt = 0, min = 1234567890;
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v1.push_back(x);
	}
	for (int j = 0; j < m; j++) {
		cin >> x;
		v2.push_back(x);
	}
	sort(v1.begin(), v1.end());  
	sort(v2.begin(), v2.end());
	int i = 0, j = 0;
	while (i<n && j<m) {
		if (abs(v1[i] - v2[j]) < min) {   //최솟값보다 작은 값이 나오면
			min = abs(v1[i] - v2[j]);  //해당 값을 최소값으로 바꾸고 카운트 초기화
			cnt = 1;
		}
		else if (abs(v1[i] - v2[j]) == min)  //최솟값과 같으면
			cnt++;
		if (v1[i]-v2[j]>0) 
			j++;
		else
			i++;
	}
	cout << min + abs(c1 - c2) << " " << cnt;
}
