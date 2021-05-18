#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int N, C;
	int arr[200001];
	int MIN = 1000000007;
	int ret = 0;

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int high = arr[N - 1], low = 0, mid;
	int pos, count;
	while (low <= high) { // 이분 탐색 시작
		mid = (low + high) / 2;
		pos = 0, count = 1;    //가장 첫번째 arr[0]에는 바로 설치하고 시작
		for (int i = 1; i < N; i++) {
			if (arr[i] - arr[pos] >= mid) { // 만약 거리가 mid보다 크거나 같으면
				pos = i; // 그때의 위치를 pos에 저장
				count++; // 설치되는 공유기 개수를 세기 위함
			}
		}
		if (count >= C) { // 설치한 공유기 수가 C와 같아지면
			if (ret < mid)
				ret = mid; 
			low = mid + 1; // low 값을 갱신
		}
		else
			high = mid - 1; // 그게 아니라면 high 값을 갱신
	}

	cout << ret;
	return 0;
}
