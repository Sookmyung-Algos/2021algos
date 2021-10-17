#include <iostream>
#include <vector>
using namespace std;

int N, K, Q, M, S, E;
bool issleep[5004];
bool ischecked[5004];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, sum, i;
	cin >> N >> K >> Q >> M;
	v.resize(N + 3, 0);
	for (i = 0; i < K; i++) {
		cin >> num;
		issleep[num] = 1;
	}
	for (i = 0; i < Q; i++) {
		cin >> num;
		if (issleep[num] == 1) continue;
		sum = num;
		for (int j = num; j <= N + 2;) {
			if (issleep[j]) {
				j += sum;
				continue;
			}
			ischecked[j] = 1;
			j += sum;
		}
	}
	for (i = 3; i <= N + 2; i++)
		v[i] = v[i - 1] + (ischecked[i] == 0);
	for (i = 0; i < M; i++) {
		cin >> S >> E;
		cout << v[E] - v[S - 1] << "\n";
	}
	return 0;
}
