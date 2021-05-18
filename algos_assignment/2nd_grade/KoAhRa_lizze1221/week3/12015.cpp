#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1000001];
vector<int> sequence;
int N;

void binary_search(int num) { // 이분 탐색을 위한 함수
	int low = 0, high = sequence.size() - 1, mid;
	int ret = 1000000007;
	while (low <= high) {
		mid = (low + high) / 2;
		int here_num = sequence[mid];
		if (here_num >= num) { // 만약 here_num보다 작은 수라면
			if (ret > mid)
				ret = mid;
			high = mid - 1; // high값을 갱신
		}
		else
			low = mid + 1; // 그게 아니라면 low 값을 갱신
	}

	sequence[ret] = num;
}

void find_lis() {
	sequence.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (sequence.back() < arr[i]) { // 만약 이전의 값이 작다면
			sequence.push_back(arr[i]); // push back
		}
		else { // 그게 아니라면 이분 탐색 시작
			binary_search(arr[i]);
		}
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	find_lis();

	cout << sequence.size(); // 마지막에 sequence size 출력해주기

	return 0;
}
