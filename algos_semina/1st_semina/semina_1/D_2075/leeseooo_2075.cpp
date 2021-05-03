#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //시간초과 해결
	int n, num;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num); //오름차순으로 pq에 push
	}

	for (int i = 1; i < n; i++) { //메모리 초과 해결
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
		}
		for (int i = 0; i < n; i++) //작은 수 pop
			pq.pop();
	}
	cout << pq.top(); //작은 순서로 정렬하고 n개씩 pop했으므로 top에는 n번째로 큰 수가 위치함
	return 0;
}
