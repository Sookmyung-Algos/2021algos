#include <iostream>
using namespace std;

int n, k;
int doll[1000001] = { 0, }; 

int main() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> doll[i];
	}

	int left = 0, right = 0; // 포함하는 인형의 맨 왼쪽과 오른쪽 인덱스
	int cnt=(doll[left]==1)?1:0; // 라이언 인형의 개수
	int val = n; // 인형들의 집합의 크기
	int min = n; // 가장 작은 인형들의 집합의 크기
	while (left<=right&&right<n) {
		if (cnt < k) { 
			right++;
			if (doll[right] == 1) cnt++;
		}
		else if (cnt == k) {
			val = right - left + 1;
			min = (val < min) ? val : min;

			if (doll[left] == 1) cnt--;
			left++;
		}
		else { // cnt>k
			if (doll[left] == 1) cnt--;
			left++;
		}
	}

	if (min == n) cout << "-1" << endl;
	else cout << min << endl;
}
