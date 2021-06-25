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
        return tree[node] = max(init(a, tree, node * 2, start, (start + end) / 2), init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

long long run(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return max(run(tree, node * 2, start, (start + end) / 2, left, right), run(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    for (int i = m - 1; i < n - m + 1; i++) {
        int s = i - m + 1;
        int e = i + m - 1;
        cout << run(tree, 1, 0, n-1, s, e) << " ";
    }
    return 0;
}
