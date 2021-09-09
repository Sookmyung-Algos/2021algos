#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, result = 0, idx = 0;

	vector<int> box;
	vector<int> crane;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		crane.push_back(c);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;
		box.push_back(c);
	}

	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	if (crane[0] < box[0]) {
		cout << "-1\n";
		return 0;
	}

	while (box.size() != 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
		result++;
	}

	cout << result << "\n";
	return 0;
}
