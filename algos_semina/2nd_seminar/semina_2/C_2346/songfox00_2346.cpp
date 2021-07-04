#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>>v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back({ i,a });
	}
	
	int pos = 0;
	while(true){
		cout << v[pos].first << ' ';
		int next = v[pos].second;
		v.erase(v.begin() + pos);
		if (v.empty())
			break;
		if (next > 0)
			pos = (pos + next - 1) % v.size();
		else {
			pos += next;
			while (pos < 0)
				pos += v.size();
		}
	}
	return 0;
}
