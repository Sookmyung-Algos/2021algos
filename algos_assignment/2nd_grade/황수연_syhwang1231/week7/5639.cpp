// 5639: 이진 검색 트리(Silver 1)
#include <iostream>
#include <vector>
using namespace std;

int tree[1000001][2];  // 1000001인 이유는 키 값이 10의 6제곱보다 작은 양수이기 때문!
int root;
int cur;

void setPreOrder(int x) {
	cur = root;  // 실행때마다 cur를 루트 노드(예제:50)로 갱신
	while(1){
		if (x < cur) {  // 새 입력이 현재의 루트(cur)보다 작으면
			if (tree[cur][0] == 0) {  // 왼쪽 자식 노드 비었으면
				tree[cur][0] = x;
				break;
			}
			else  // 왼쪽 자식 노드 안비었으면
				cur = tree[cur][0];  // 루트 노드를 현재의 왼쪽 자식 노드로 갱신
		}
		else {  // 새 입력이 현재의 루트(cur)보다 크면
			if (tree[cur][1] == 0) {  // 오른쪽 자식 노드 비었으면
				tree[cur][1] = x;
				break;
			}
			else
				cur = tree[cur][1];
		}
	}
}

void postOrder(int root) {  // 후위 수식: 왼-오-루트
	if (tree[root][0] != 0)  // 왼쪽 자식 노드가 존재하면
		postOrder(tree[root][0]);
	if (tree[root][1] != 0)
		postOrder(tree[root][1]);
	cout << root << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> root;  // 전위순회이므로 첫번째 값은 루트 노드의 키
	while (cin >> n) {
		if (n == EOF)
			break;
		setPreOrder(n);
	}
	postOrder(root);
	return 0;
}
