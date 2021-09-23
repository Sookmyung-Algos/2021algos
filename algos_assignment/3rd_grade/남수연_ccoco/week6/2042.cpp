#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, long long node, long long start, long long end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        
    }
}

void update(vector<long long> &tree, long long node, long long start, long long end, long long index, long long d) {
    if (index < start || index > end) return;
    // 차이만큼 더해주고 갱신
    tree[node] = tree[node] + d;
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, d);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, d);
    }
}

long long sum(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(int argc, const char * argv[]) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    m += k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    while (m--) {
        int t1;
        cin >> t1;
        if (t1 == 1) {
            long long t2, t3;
            cin >> t2 >> t3;
            t2 -= 1;
            long long d = t3 - a[t2];
            a[t2] = t3;
            update(tree, 1, 0, n-1, t2, d);
        } else if (t1 == 2) {
            long long t2, t3;
            cin >> t2 >> t3;
            printf("%lld\n", sum(tree, 1, 0, n-1, t2-1, t3-1));
        }
    }
    return 0;
}
