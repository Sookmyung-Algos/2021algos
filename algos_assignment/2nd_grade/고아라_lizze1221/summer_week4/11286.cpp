#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct st{
	int num;
	int num_abs;
};

struct cmp{
	bool operator()(st n1, st n2){
		if(n1.num_abs == n2.num_abs) return n1.num > n2.num;
		else return n1.num_abs > n2.num_abs;
	}
};

priority_queue<st, vector<st>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if(a!=0) {
			pq.push({a, abs(a)});
		}
		else{
			if(!pq.empty()) {
				cout << pq.top().num << "\n";
				pq.pop();
			}
			else cout <<"0\n";
		}
	}
	return 0;
}
