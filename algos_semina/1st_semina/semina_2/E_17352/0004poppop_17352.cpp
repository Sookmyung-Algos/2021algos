#include<iostream>
#define MAX 300001
using namespace std;
int parent[MAX];

// 유니온파인드 알고리즘

int find(int x) { // 루트 노드 찾아주는 함수
	if (parent[x] == x) // 루트 노드일 때
		return x;
	return parent[x] = find(parent[x]); // 재귀적으로 부모 노드를 찾아 루트 노드 반환
}


void merge(int x, int y) { // 두 노드 이어주는 함수
	x = find(x); // 루트 찾기
	y = find(y); // 루트 찾기
  
	if (x == y) // 루트가 같다면
		return; // 이미 같은 트리이므로 루트 변경을 통해 이어줄 필요 없음
  
	parent[y] = x; // y의 루트가 x가 됨
}

bool isUnion(int x, int y) { // 두 노드의 루트가 같은지 = 두 섬이 이어져 있는지 확인하는 함수
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
	int n; 
  cin >> n;
  
	for (int i = 0; i < MAX; i++)
		parent[i] = i; // parent[i]를 노드 i의 부모 노드라고 정의

	for (int i = 0; i < n - 2; i++) {
		int a, b; 
    cin >> a >> b; // n-2개 다리들로 연결되어 있는 섬들 입력
		merge(a, b); // merge함수를 이용해 루트노드 일치시킴
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (!isUnion(i, j)) // 두 섬이 이어져 있지 않을 때 = 루트가 다를 때
			{
				cout << i << ' ' << j;
				return 0;
			} // 두 섬 번호 출력
		}
	}
	return 0;
}
