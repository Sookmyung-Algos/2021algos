#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back({ i + 1,num });
	}
	int index = 0, cnt = n;
	for (int i = 0; i < n; i++) {
		cout << v[index].first<<" ";
		int go = v[index].second;
		v.erase(v.begin() + index);
		if (go > 0) {
			go--;
		}
		index += go;
		if (--cnt == 0) {
			break;
		}
		if (index < 0) {
			index = cnt + index % cnt;
		}
		index %= cnt;
	}
	cout << "\n";
	return 0;
}
