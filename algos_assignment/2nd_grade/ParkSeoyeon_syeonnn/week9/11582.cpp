//11582 치킨 TOP N

#include <iostream>
using namespace std;

int temp[1048577];
int result[1048577];

int n, limit;

void merge(int left, int right) {
	if (right - left > n / limit)
		return;	// 주어진 인원 수 만큼 정렬을 진행했을 때 현재 상태 출력

	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (temp[i] > temp[j]) {
			result[k++] = temp[j++];
		}
		// 양쪽 리스트에서 최솟값을 비교했는데 오른쪽 리스트가 더 컸을 경우
		// 왼쪽 리스트의 최솟값이 결과배열에 내려옴 
		else {
			result[k++] = temp[i++];
		}
	}

	// 오른쪽 리스트에 남은 값들 차례로 마저 넣음
	if (i > mid) {
		while (j <= right) {
			result[k++] = temp[j++];
		}
	}
	else { // 왼쪽 리스트에 남은 값들 차례로 마저 넣음
		while (i <= mid) {
			result[k++] = temp[i++];
		}
	}

	// 다시 원래 배열에 옮겨담음
	for (int ㅣ = left; ㅣ <= right; ㅣ++) {
		temp[ㅣ] = result[ㅣ];
	}
}

void merge_sort(int left, int right) {
	int mid;

	// 재귀, 반복을 통해 분할, 병합
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}


}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> temp[i];

	cin >> limit;

	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << temp[i] <<' ';

	return 0;
}
