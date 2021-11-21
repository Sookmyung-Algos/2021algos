#include <iostream>
#include <map>
using namespace std;

map<string, string> m;

string find(string x){
	if(m[x][0] == '-') return x;
	return m[x] = find(m[x]);
}

void merge(string x, string y){
	if((x = find(x)) == (y = find(y))) return;
	if(m[x] < m[y]){
		m[x] = to_string(stoi(m[x]) + stoi(m[y]));
		m[y] = x;
	}
	else{
		m[y] = to_string(stoi(m[y]) + stoi(m[x]));
		m[x] = y;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		m.clear();
		int f;
		cin >> f;
		while (f--) {
			string a, b;
			cin >> a >> b;
			if (m.find(a) == m.end())
				m.insert({a, "-1"});
			if (m.find(b) == m.end())
				m.insert({b, "-1"});
			merge(a, b);
			cout << -stoi(m[find(a)]) << "\n";
		}
	}
	return 0;
}
