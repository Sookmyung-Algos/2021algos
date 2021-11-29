// G1_11505 구간 곱 구하기

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#define ll long long
#define MOD 1000000007
#define MAX 1000001
using namespace std;

int N, M, K; // 수의 개수, 변경횟수, 구간의 곱 횟수
int input[MAX];
vector <ll> segment;
vector <pair<pair<ll, ll>,ll>> v;
// 순서대로 저장해서 꺼내서 

ll make_segment(int node, int start, int end) {
	if (start == end)
		return segment[node] = input[start] % MOD;

	int mid = (start + end) / 2;
	ll left = make_segment(node * 2, start, mid);
	ll right = make_segment(node * 2 + 1, mid + 1, end);
	segment[node] = (left * right) % MOD;
	return segment[node];
}

ll update(int node, int start, int end, int idx, ll num){
	if (idx < start || end < idx)
		return segment[node];
	if (start == end)
		return segment[node] = num;

	int mid = (start + end) / 2;
	ll left = update(node * 2, start, mid, idx, num);
	ll right = update(node * 2 + 1, mid + 1, end, idx, num);
	ll result = (left * right) % MOD;

	return segment[node] = result;
}

ll multiple(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return segment[node];

	int mid = (start + end) / 2;
	ll leftnode = multiple(node * 2, start, mid, left, right);
	ll rightnode = multiple(node * 2 + 1, mid + 1, end, left, right);
	return (leftnode * rightnode) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		// 해당 부분의 값 등 편하게 접근하려고 배열 사용
		cin >> input[i];
	}
	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(b, c), a));
	}

	int tree_height = (int)ceil(log2(N)); // 트리 높이
	int tree_size = (1 << (tree_height + 1));
	segment.resize(tree_size);
	make_segment(1, 0, N - 1);

	for (int i = 0; i < v.size(); i++){
		int command = v[i].second;
		if (command == 1) { // 숫자 바꾸기
			int idx = v[i].first.first - 1;
			ll num = v[i].first.second;
			update(1, 0, N - 1, idx, num);
		}
		else{
			int n1 = v[i].first.first - 1;
			int n2 = v[i].first.second - 1;
			cout << multiple(1, 0, N - 1, n1, n2) % MOD << endl;
		}
	}
	return 0;
}
