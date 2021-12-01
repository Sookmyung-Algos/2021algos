//1275 커피숍2
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
int N, Q;
vector<long long> number;
vector<long long> segmentTree;

long long init(int start, int end, int idx) {
    if(start + 1 == end) {
        segmentTree[idx] = number[start];
        return segmentTree[idx];
    }
    int mid = (start + end)/2;
    segmentTree[idx] = init(start, mid, idx*2) + init(mid, end, idx*2 + 1);
    return segmentTree[idx];
}
 
void update(int ni, long long x, int start, int end, int idx) {
    int mid = (start + end)/ 2;
    segmentTree[idx] += (x - number[ni]);
    
    if(start + 1 == end) return;
    if(ni < mid) return update(ni , x, start, mid, idx*2);
    else return update(ni , x, mid, end, idx*2+1);
}
 
long long find(int start, int end, int idx, int low, int high) {
    if(start == low && end == high ) {
        return segmentTree[idx];
    }
    int mid = (low + high)/2;
    if (end <= mid) return find(start, end, idx*2, low, mid);
    else if (mid <= start) return find(start, end, idx*2 + 1, mid, high);
    else return find(start, mid, idx*2, low, mid) + find(mid, end, idx*2+1, mid, high);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    number = vector<long long> (N);
    segmentTree = vector<long long> (N*4);
    
    for(int i = 0; i < N; i++) {
        cin >> number[i];
    }
    
    init(0, N, 1);
    
    for(int i = 0; i < Q; i++) {
        int lo, hi, ni;
        long long x;
        cin >> lo >> hi >> ni >> x;
        if (lo > hi) swap(lo, hi);
    
        cout << find(lo - 1, hi, 1, 0, N) << "\n";
        update(ni - 1, x, 0, N, 1);
        number[ni-1] = x;
    }
}
