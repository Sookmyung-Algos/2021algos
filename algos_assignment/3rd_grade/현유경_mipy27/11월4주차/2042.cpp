//2042 구간 합 구하기

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

// 세그먼트 트리 만들기
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) { // node가 리프노드인 경우
        return tree[node] = a[start]; // 리프노드는 배열의 그 원소를 가져야해서 tree[node]에 저장
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
        // 왼쪽 트리 생성 + 오른쪽 트리 생성
    }
}

// 세그먼트 트리 수정하기
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}

// 세그먼트 트리에 구간합 저장하기
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    vector<long long> arr(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    m += k;
    for (int i=0; i<n; i++) {
        scanf("%lld",&arr[i]);
    }
    init(arr, tree, 1, 0, n-1);
    while (m--) {
        int a;
        scanf("%d",&a);
        if (a == 1) {
            int b;
            long long c;
            scanf("%d %lld",&b,&c);
            b-=1;
            long long diff = c-arr[b];
            arr[b] = c;
            update(tree, 1, 0, n-1, b, diff);
        } else if (a == 2) {
            int b,c;
            scanf("%d %d",&b,&c);
            printf("%lld\n",sum(tree, 1, 0, n-1, b-1, c-1));
        }
    }
    return 0;
}
