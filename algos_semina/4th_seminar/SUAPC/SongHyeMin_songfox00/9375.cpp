#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, int>m;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	
	while (t--) {
		m.clear();

		int n;
		cin >> n;
		string name, kind;

		for (int i = 0; i < n; i++) {
			cin >> name >> kind;

			if (m.find(kind)==m.end()) {
				m.insert({ kind,1 });
			}
			else {
				m[kind]++;
			}
		}

		int res = 1;

		map<string, int>::iterator it;
		for (it=m.begin(); it!=m.end();it++)
			res *= (it->second + 1);

		cout << res-1<<'\n';
	}

	return 0;
}
