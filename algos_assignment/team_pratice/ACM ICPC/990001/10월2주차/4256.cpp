// 4256 트리

// 중위 순회 결과를 통해 각 노드의 순서를 알 수 있고, 왼쪽 서브 트리와 오른쪽 서브 트리에 어떤 노드가 존재하는지 알 수 있다.
// 전위 순회 결과를 통해서는 규칙을 찾아볼 수 있는데 크기가 n인 배열에 전위 순회 결과가 차례로 저장되어 있다고 했을 때 index+1을 하면 왼쪽 서브 트리의 루트를 가리키게 할 수 있다.

#include <iostream>
using namespace std;

int T;
int preorder[1001];
int inorder[1001];

void solve(int start,int end,int node){
    for (int i=start;i<end;i++){
        if (preorder[node] == inorder[i]){
            solve(start,i,node+1); // left sub 트리
            solve(i+1,end,node+i+1-start); // right sub tree
            cout << preorder[node] << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    
    while (T--){
        int n;
        cin >> n;
        
        int a;
        // 전위 수식 결과 저장
        for (int i=0;i<n;i++){
            cin >> preorder[i];
        }
        // 중위 수식 결과 저장
        for (int i=0;i<n;i++){
            cin >> inorder[i];
        }
        solve(0,n,0);
        cout << '\n';
    }
}
