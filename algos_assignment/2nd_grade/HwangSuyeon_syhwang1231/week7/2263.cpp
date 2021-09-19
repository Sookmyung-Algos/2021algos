// 2263: 트리의 순회(Gold 3)
#include <iostream>
#define MAX 100001
using namespace std;

int n;
int inIndex[MAX];  // 인덱스: 노드 번호, 원소: inorder배열에서의 인덱스
int inorder[MAX];
int postorder[MAX];

// inorder와 postorder 배열을 leftchild, rightchild로 각각 분할 하면서 preorder 구하기
void getPreOrder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd)  // 종결조건
        return;
    int rootIndex = inIndex[postorder[postEnd]];  // postorder의 마지막 노드는 (서브)트리의 루트 노드
    int leftSize = rootIndex - inStart;  // 왼쪽 서브트리의 개수
    int rightSize = inEnd - rootIndex;  // 오른쪽 서브트리의 개수
    
    cout << postorder[postEnd] << ' ';  // preorder의 특징에 따라 루트 노드 출력
    
    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);  // 왼쪽 서브트리
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);  // 오른쪽 서브트리 
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> inorder[i];
        inIndex[inorder[i]] = i;
    }
    for(int i=1; i<=n; i++)
        cin >> postorder[i];
    
    getPreOrder(1, n, 1, n);  // inorder의 1부터 n번(포함)까지, postorder의 1부터 n번(포함)까지
    return 0;
}
