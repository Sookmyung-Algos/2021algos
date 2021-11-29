#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int sizes[200002];
int link[200002];

int find(int x) {
	if (link[x] == x) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
    if( a != b ){
		if (sizes[a] < sizes[b]) swap(a, b);
		sizes[a] += sizes[b];
		link[b] = a;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
	int t, F, p1, p2;
	cin >> t;
	string in1, in2;
	for (int T = 0; T < t; T++) {
		cin >> F;
		for (int i = 0; i < 200002; i++) {
			sizes[i] = 1;
			link[i] = i;
		}
		map<string, int> map;
		int nodeNum = 1;
		for (int i = 0; i < F; i++) {
			cin >> in1 >> in2;
			if (map.count(in1) == 0) map[in1] = nodeNum++;		
			if (map.count(in2) == 0) map[in2] = nodeNum++;
            unite(map[in1], map[in2]);
            p1 = find(map[in1]);
            p2 = find(map[in2]);
			cout << max(sizes[p1], sizes[p2]) << '\n';	
		}
	}
    return 0;
}
