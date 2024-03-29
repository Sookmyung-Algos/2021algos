#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start==end)
        return tree[node]=a[start];
    else
        return tree[node] = init(a, tree, node*2, start, (start+end)/2)+init(a, tree, node*2+1, (start+end)/2+1, end);

}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index<start || index>end) return;
    tree[node] = tree[node] + diff;
    if(start!=end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(right<start || left>end) return 0;
    if(left<=start && end<=right) return tree[node];
    return sum(tree, node*2, start, (start+end)/2, left, right)+sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    int size = (1 << (h+1));
    vector<long long> arr(n);
    vector<long long> tree(size);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    init(arr, tree, 1, 0, n-1);
    for(int i=0;i<(m+k);i++){
        int a;
        cin >> a;
        if(a==1){
            int b;
            long long c;
            cin >> b >> c;
            long long diff = c-arr[b-1];
            arr[b-1]=c;
            update(tree, 1, 0, n-1, b-1, diff);
        }
        else if (a==2){
            int b, c;
            cin >> b >> c;
            cout << sum(tree, 1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}
