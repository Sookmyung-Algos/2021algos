// 1275 커피숍2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;

vector<long long> arr;
vector<long long> tree;

long long init(int start, int end, int idx) {
    if (start + 1 == end) {
        return tree[idx] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[idx] = init(start, mid, idx * 2) + init(mid, end, idx * 2 + 1);
}

void update(int node, int start, int end, int index, long long val) {
    int mid = (start + end) / 2;
    tree[node] += (val - arr[index]);

    if (start + 1 == end) 
        return;
    if (index < mid)
        return update(node * 2, start, mid, index, val);
    else 
        return update(node * 2 + 1, mid, end, index, val);
}

long long query(int node, int start, int end, int left, int right) {
    if (start == left && end == right) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    if (end <= mid) 
        return query(node * 2, start, end, left, mid);
    else if (mid <= start) 
        return query(node * 2+1, start, end, mid, right);
    else 
        return query(node * 2, start, mid, left, mid) + query(node * 2 + 1, mid, end, mid, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    arr = vector<long long>(N);
    tree = vector<long long>(N * 4);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init(0, N, 1);

    for (int i = 0; i < Q; i++) {
        int x,y,a;
        long long b;
        cin >> x >> y >> a >> b;    // x~y 합 구하기, a번째 수를 b로 바꾸기

        if (x > y) 
            swap(x, y);

        cout << query(1, x - 1, y, 0, N) << "\n";
        update(1, 0, N, a - 1, b);
        arr[a - 1] = b;
    }
}
