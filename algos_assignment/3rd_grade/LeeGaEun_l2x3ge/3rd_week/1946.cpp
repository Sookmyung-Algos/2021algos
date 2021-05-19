#include <iostream> 
#include <vector>
#include<algorithm>
using namespace std;
int main(void){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t, n;
	cin >> t;
	for (int i = 0;i < t;i++) {
		vector<pair<int, int>> v;
		cin >> n;
		for (int j = 0;j < n;j++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		int count = 1, rank = v[0].second;
		for (int j = 1;j < n;j++) {
			if (rank > v[j].second) {
				count++;
				rank = v[j].second;
			}
		}
		cout << count << "\n";
	}
}
