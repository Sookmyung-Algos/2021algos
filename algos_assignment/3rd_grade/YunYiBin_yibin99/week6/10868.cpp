#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> arr, min_tree;

void init(int node, int start, int end){
    if(start==end)
        min_tree[node]=arr[start];
    else{
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        min_tree[node]=min(min_tree[node*2], min_tree[node*2+1]);
    }
    return;
}

int find(int node, int start, int end, int left, int right){
    if(right<start || left>end) return 1000000001;
    if(left<=start && end<=right) return min_tree[node];
    int cand1 = find(node*2, start, (start+end)/2, left, right);
    int cand2 = find(node*2+1, (start+end)/2+1, end, left, right);
    return min(cand1, cand2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int size=(1<<((int)ceil(log2(n))+1));
    arr.resize(n);
    min_tree.resize(size);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    init(1, 0, n-1);
    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        cout << find(1, 0, n-1, a-1, b-1) << "\n";
    }
}
