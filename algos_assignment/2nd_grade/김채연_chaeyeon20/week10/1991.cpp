#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector < pair<int,int> > v(100);
int chk[26][2];

void preorder(char root){
    cout << root;
    if(v[root].first != '.') preorder(v[root].first);
    if(v[root].second != '.') preorder(v[root].second);
}

void inorder(char root){
    if(v[root].first != '.') inorder(v[root].first);
    cout << root;
    if(v[root].second != '.') inorder(v[root].second);
}

void postorder(char root){
    if(v[root].first != '.') postorder(v[root].first);
    if(v[root].second != '.') postorder(v[root].second);
    cout << root;
}

int main() {
    cin >> N; 
    for(int i=0; i<N; i++){
        char root, left, right;
        cin >> root >> left >> right;
        v[root] = {left, right};
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0; 
    }
