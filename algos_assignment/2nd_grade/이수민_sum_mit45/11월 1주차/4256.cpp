#include <iostream>
#include <vector>
using namespace std;
 
int preorder[1001];
int inorder[1001];

void check(int root, int s, int e){
    for(int i = s ; i < e; i++){
        if(inorder[i] == preorder[root]){
            check(root + 1, s, i); // left sub tree
            check(root + i + 1 - s, i + 1, e); // right sub tree
            cout<<preorder[root]<<" ";
        }
    }
}
 
int main(void) {
    int test_case; cin>>test_case;
    while(test_case--){
        int n ; cin>>n;
        for(int i=0; i<n; i++)
            cin >> preorder[i];
        for(int i=0; i<n; i++)
            cin >> inorder[i];
        check(0, 0, n);
        cout << "\n";
    }
    return 0;
}
