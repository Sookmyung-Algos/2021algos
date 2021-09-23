#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[4000001];
vector <int> prime;

int main() {
	cin >> N;

	for (int i = 2; i <= 4000001; i++)
	{
		if (arr[i] == 0) {
			prime.push_back(i);
			for (int j = 2; i*j <= 4000001; j++)
			{
				if (arr[i * j] == 0) {
					arr[i * j] = 1;
				}
			}
		}
	}

	int a = 0, b = 0;
	int total = 2;
	int cnt = 0;
	while (b < prime.size() - 1) {
		if (total == N) { // N과 같으면
			cnt++; // 하나 발견했으므로 cnt에 1더하기
			b++;
			total += prime[b] - prime[a];
			a++;
		}
		else if (total < N) { // 만약 작으면
			b++;
			total += prime[b]; // 가장 오른쪽 수 더해주기
		}
		else { // 만약 크면
			total -= prime[a]; // 가장 왼쪽 수 빼주기
			a++;
		}
	}

	cout << cnt;

	return 0;
}
