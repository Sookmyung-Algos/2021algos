// 2243 사탕상자

#include<iostream>
#include<vector>
#include<cmath>
#define MAX 1000000

using namespace std;

int N;
int arr[MAX + 10];
vector<int> tree; 
vector<pair<int, pair<int, int>>> cmd;

int query(int node, int start, int end, int cnt) {
    if (start == end) 
        return start;

    int mid = (start + end) / 2;

    // [start, mid]에 cnt 있다면, (2*node, start, mid, cnt) 리턴
    // tree[2*node] = [start, mid]에 사탕 개수
    if (tree[node * 2] >= cnt) 
        return query(node * 2, start, mid, cnt);

    // 만약[mid + 1, ed]에 cnt 있다면, cnt - tree[2 * node]번째 리턴
    return query(node * 2 + 1, mid + 1, end, cnt - tree[node * 2]);
}

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end)
        return;
    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

void solution() {
    int tree_height = (int)ceil(log2(MAX));
    int tree_size = 1 << (tree_height + 1);
    tree.resize(tree_size);

    for (int i = 0; i < cmd.size(); i++) {
        int command = cmd[i].first;
        if (command == 1){
            int idx = cmd[i].second.first;
            int pos = query(1, 1, MAX, idx);    // idx번째 수 찾기
            cout << pos << "\n";
            arr[pos]--;
            update(1, 1, MAX, pos, -1);
        }

        else{
            int index = cmd[i].second.first;
            int value = cmd[i].second.second;
            arr[index] = arr[index] + value;
            update(1, 1, MAX, index, value);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;

         // a = 1이면 사탕 꺼냄
        if (a == 1) {
            int b; cin >> b;    // 꺼내는 사탕의 순위
            cmd.push_back({ a, {b, -1}});
        }

        // a = 2이면 사탕 넣음
        else {
            int b, c; cin >> b >> c;    // 넣는 사탕의 맛, 넣는 사탕의 개수
            cmd.push_back({ a, {b, c} });
        }
    }

    solution();

    return 0;
}
