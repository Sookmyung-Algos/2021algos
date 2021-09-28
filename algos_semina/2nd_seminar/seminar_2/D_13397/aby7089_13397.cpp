#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
int n, m;

int check(int mid) {
	vector <int> chk;
	int cnt = 1; //구간 개수
	int minV, maxV;
	minV = v[0];
	maxV = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] < minV) minV = v[i]; 
		if (v[i] > maxV) maxV = v[i];
		if ((maxV - minV) > mid) { //차가 mid보다 크면 구간 개수+1
			cnt++;
			minV = v[i];
			maxV = v[i];
		}
	}
	if (cnt <= m) //m개 이하의 구간 만족
		return 1;
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, max = 0;
	int left = 0, right;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (max < k)
			max = k;
		v.push_back(k);
	}
	right = max; //입력값 중 최댓값을 right로 설정
	int answer = right;
	while (left <= right) { //이분탐색
		int mid = (right + left) / 2;
		if (check(mid)) {
			if (mid < answer)
				answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << answer;
}
