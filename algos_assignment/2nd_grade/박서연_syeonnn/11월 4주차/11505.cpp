// 11505 구간 곱 구하기
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

// 세그먼트 트리 만들기
long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end){
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = (init(arr, tree, node * 2, start, mid) * init(arr, tree, node * 2 + 1, mid + 1, end)) % 1000000007;
}

// 세그먼트 트리 수정하기
void update(vector<long long>& tree, int node, int start, int end, int index, long long val){
	// 변경하려는 인덱스가 탐색 범위 벗어났다면 하위 노드 탐색 종료
	if (index<start || index>end)
		return;

	if (start == end)
	{
		tree[node] = val;
		return;
	}

	// 아니라면 해당 노드에 val 값 곱하기
	//tree[node] *= val;

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, val);
		update(tree, node * 2 + 1, mid + 1, end, index, val);
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
	}
}

// 세그먼트 트리 구간 곱 저장하기
long long query(vector<long long>& tree, int node, int start, int end, int left, int right){
	// [start,end]범위가 [left,end]와 전혀 겹치지 않는 경우
	if (left > end || right < start)
		return 1;	 // 탐색 종료

	// [start,end]범위가 [left,end]에 완전히 속해 있는 경우
	if (left <= start && end <= right)
		return tree[node];	// [start,end] 합 반환

	// 그외의 경우 하위 범위 탐색
	int mid = (start + end) / 2;
	return (query(tree, node * 2, start, mid, left, right) * query(tree, node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k; // 수의 개수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1)); 

	vector<long long> arr(n+1); // 입력받아 생성된 배열
	vector<long long> tree(tree_size); // 세그먼트 트리가 만들어지는 배열

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 1, n);

	m += k; // m+k번 반복

	while (m--){
		int a;
		cin >> a;

		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;
			update(tree, 1, 1, n, b, c);
		}

		else if (a == 2)
		{
			int b, c;
			cin >> b >> c;
			if (b >= c)
				swap(b, c);
			cout << query(tree, 1, 1, n, b, c) << "\n";
		}
	}
	return 0;
}
