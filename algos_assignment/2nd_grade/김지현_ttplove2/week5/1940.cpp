#include <iostream>
#define MAX 15001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	int cnt = 0;
	int arr[MAX];
	bool check[MAX];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		check[i] = false;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!check[i] && !check[j] && arr[i] + arr[j] == M) {
				cnt++;
				check[i] = check[j] = true;
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}
