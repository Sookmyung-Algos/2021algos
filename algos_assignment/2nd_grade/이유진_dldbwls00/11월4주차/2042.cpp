//복습할것
#include<iostream>
#include<vector>
#include<cmath>

typedef long long ll;
using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> treeArray;
vector<pair<int, pair<int, long long>>> cmd;

void input(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < m + k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cmd.push_back(make_pair(a, make_pair(b, c)));
    }
}

long long makeSeg(int node, int start, int end){
    if (start == end) return treeArray[node] = arr[start];

    int mid = (start + end) / 2;
    
    return makeSeg(node * 2, start, mid) + makeSeg(node * 2 + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right){
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return treeArray[node];

    int mid = (start + end) / 2;
    
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff){
    if (idx < start || idx > end) return;
    treeArray[node] = treeArray[node] + diff;

    if (start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}
void solution(){
    int height = (int)ceil(log2(n));
    int treesize = (1 << (height + 1));
    treeArray.resize(treesize);
    makeSeg(1, 0, n - 1);

    for (int i = 0; i < cmd.size(); i++){
        int command = cmd[i].first;
        if (command == 1){
            int idx = cmd[i].second.first - 1;
            long long val = cmd[i].second.second;
            long long diff = val - arr[idx];
            arr[idx] = val;
            update(1, 0, n - 1, idx, diff);
        }
        else
            cout << sum(1, 0, n - 1, cmd[i].second.first - 1, cmd[i].second.second - 1);

    }
}

int main(void){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cmd.push_back(make_pair(a, make_pair(b, c)));
    }
    solution();
    return 0;
}
