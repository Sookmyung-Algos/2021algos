#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, score, P, rank = 1, sameN = 0;
	int arr[51];

	cin >> N >> score >> P;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (N == P && score <= arr[N - 1]) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] > score) rank++;
		if (arr[i] >= score) sameN++;
	}
	cout << rank << "\n";
	return 0;
}
