#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> arr;
vector<long long> tree;

long long init(int node, int start, int end){
    if(start==end)
        return tree[node] = arr[start];
    return tree[node] = (init(node*2, start, (start+end)/2)*init(node*2+1, (start+end)/2+1, end))%1000000007;
}

long long update(int node, int start, int end, int index, int newV){
    if(index<start || index>end) return tree[node];
    if(start==end)
        return tree[node]=newV;
    return tree[node] = (update(node*2, start, (start+end)/2, index, newV)*update(node*2+1, (start+end)/2+1, end, index, newV))%1000000007;
}

long long mul(int node, int start, int end, int left, int right){
    if(right<start || left>end) return 1;
    if(left<=start && end<=right)
        return tree[node];
    return (mul(node*2, start, (start+end)/2, left, right)*mul(node*2+1, (start+end)/2+1, end, left, right))%1000000007;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    int size = (1 << (h+1));
    arr.resize(n);
    tree.resize(size);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    init(1, 0, n-1);
    for(int i=0;i<m+k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            update(1, 0, n-1, b-1, c);
        }
        else if(a==2){
            cout << mul(1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}
