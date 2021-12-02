// 2042 구간 합 구하기

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

// 세그먼트 트리 만들기
long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

// 세그먼트 트리 수정하기
void update(vector<long long>& tree, int node, int start, int end, int index, long long val)
{
	// 변경하려는 인덱스가 탐색 범위 벗어났다면 하위 노드 탐색 종료
	if (index<start || index>end)
		return;

	// 아니라면 해당 노드에 val 값 더하기
	tree[node] += val;
	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, val);
		update(tree, node * 2 + 1, mid + 1, end, index, val);
	}
}

// 세그먼트 트리 구간합 저장하기
long long query(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	// [start,end]범위가 [left,end]와 전혀 겹치지 않는 경우
	if (left > end || right < start)
		return 0;	 // 탐색 종료

	 // [start,end]범위가 [left,end]에 완전히 속해 있는 경우
	if (left <= start && end <= right)
		return tree[node];	// [start,end] 합 반환
	  
	 // 그외의 경우 하위 범위 탐색
	int mid = (start + end) / 2;
	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k; // 수의 개수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수

	int h = (int)ceil(log2(n)); 
	int tree_size = (1 << (h + 1)); // 트리의 크기 2^(h+1) 지정

	vector<long long> arr(n); // 입력받아 생성된 배열
	vector<long long> tree(tree_size); // 세그먼트 트리가 만들어지는 배열

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	m += k; // m+k번 반복

	while (m--)
	{
		int a;
		cin >> a;  

		// a==1라면 b번째 수를 c로 바꿈
		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;
			b--;
			long long diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, 0, n - 1, b, diff);
		}

		// a==2라면 b번째 수부터 c번째 수까지의 합을 출력 
		else if (a == 2)
		{
			int b, c;
			cin >> b >> c;
			cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}
