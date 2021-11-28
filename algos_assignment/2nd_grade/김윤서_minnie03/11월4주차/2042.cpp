#include <iostream>
#include <cmath>
using namespace std;
long long* tree;
long long v[1000001];

long long init(int node, int left, int right) {
    if (left == right) 
        return tree[node] = v[left];
    int mid = (left + right) / 2;
    return tree[node] = init(2 * node, left, mid) + init(2 * node + 1, mid + 1, right);
}

long long query(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

void update(int node, int left, int right, int idx, long long val) {
    if (idx<left || idx>right) return;
    tree[node] += val;
    if (left == right) return;
    int mid = (left+right) / 2;
    update(node * 2, left, mid, idx, val); // 왼쪽구간 
    update(node * 2 + 1, mid + 1, right, idx, val); // 오른쪽구간
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, m, k, a, b;
    long long c;
    cin >> num >> m >> k;
    int height = ceil(log2(num));
    tree = new long long[1 << (height + 1)];
    for (int i = 0; i < num; i++)
        cin >> v[i];
    init(1, 0, num - 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {   // b번째 수를 c로 바꿈
            long long val = c - v[b - 1];
            v[b - 1] = c; 
            update(1, 0, num - 1, b - 1, val);
        }
        else if (a == 2)      // b~c의 합
            cout << query(1, 0, num - 1, b - 1, c - 1) << '\n';
    }
    return 0;
}
