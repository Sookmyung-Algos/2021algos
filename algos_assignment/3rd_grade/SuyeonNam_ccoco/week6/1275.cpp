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
    long long n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(arr, tree, 1, 0, n-1);
    while (m--) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if (x > y) {
            printf("%lld\n", sum(tree, 1, 0, n-1, y-1, x-1));
        } else {
            printf("%lld\n", sum(tree, 1, 0, n-1, x-1, y-1));
        }
        long long diff = b - arr[a-1];
        arr[a-1] = b;
        update(tree, 1, 0, n-1, a-1, diff);
    }
    return 0;
}
