//2243 사탕상자

#include<iostream>
#include<vector>
#include<cmath>
#define MAX 1000000
using namespace std;
 
int N;
int arr[MAX + 5];
vector<int> SegmentTree;
vector<pair<int, pair<int, int>>> cmd;
 
int query(int node, int start, int end, int cnt){
    if (start == end) return start;
 
    int mid = (start + end) / 2;
    if (SegmentTree[node * 2] >= cnt) return query(node * 2, start, mid, cnt);
    return query(node * 2 + 1, mid + 1, end, cnt - SegmentTree[node * 2]);
}
 
void update(int node, int start, int end, int idx, int diff){
    if (idx < start || idx > end) return;
    SegmentTree[node] = SegmentTree[node] + diff;
 
    if (start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}
 
void solution(){
    int tree_height = (int)ceil(log2(MAX));
    int tree_size = 1 << (tree_height + 1);
    SegmentTree.resize(tree_size);
    
    for (int i = 0; i < cmd.size(); i++){
        int command = cmd[i].first;
        if (command == 1)
        {
            int idx = cmd[i].second.first;
            int pos = query(1, 1, MAX, idx);
            cout << pos << "\n";
            arr[pos]--;
            update(1, 1, MAX, pos, -1);
        }
        else
        {
            int idx = cmd[i].second.first;
            int value = cmd[i].second.second;
            arr[idx] = arr[idx] + value;
            update(1, 1, MAX, idx, value);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    cin >> N;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        if (a == 1){
            int b; cin >> b;
            cmd.push_back(make_pair(a, make_pair(b, -1)));
        } else{
            int b, c; cin >> b >> c;
            cmd.push_back(make_pair(a, make_pair(b, c)));
        }
    }
    
    solution();
 
    return 0;
}
