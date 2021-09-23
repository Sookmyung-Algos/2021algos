#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long min_init(vector<long long> &a, vector<long long> &tree, long long node, long long start, long long end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = min(min_init(a, tree, node * 2, start, (start + end) / 2), min_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

long long min_f(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) return 9999999999;
    if (left <= start && end <= right) return tree[node];
    return min(min_f(tree, node * 2, start, (start + end) / 2, left, right), min_f(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> min_tree(tree_size);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    min_init(a, min_tree, 1, 0, n-1);
    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        cout << min_f(min_tree, 1, 0, n-1, s-1, t-1) << '\n';
    }
    return 0;
}
