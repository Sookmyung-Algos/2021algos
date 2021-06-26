#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> min_tree, max_tree;

void init(vector<int> &arr, int node, int start, int end){
    if(start==end){
        min_tree[node] = arr[start];
        max_tree[node] = arr[start];
        return;
    }
    init(arr, node*2, start, (start+end)/2);
    init(arr, node*2+1, (start+end)/2+1, end);
    min_tree[node] = min(min_tree[node*2], min_tree[node*2+1]);
    max_tree[node] = max(max_tree[node*2], max_tree[node*2+1]);
    return;
}
pair<int, int> find(int node, int start, int end, int left, int right){
    if(right<start || left>end)
        return make_pair(1000000001, 0);
    if(left<=start&&end<=right)
        return make_pair(min_tree[node], max_tree[node]);
    pair<int, int> p1 = find(node*2, start, (start+end)/2, left, right);
    pair<int, int> p2 = find(node*2+1, (start+end)/2+1, end, left, right);
    return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int size = (1<<((int)ceil(log2(n))+1));
    vector<int> arr(n);
    min_tree.resize(size);
    max_tree.resize(size);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    init(arr, 1, 0, n-1);
    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        pair<int, int> p = find(1, 0, n-1, a-1, b-1);
        cout << p.first << " " << p.second << "\n";
    }
}
