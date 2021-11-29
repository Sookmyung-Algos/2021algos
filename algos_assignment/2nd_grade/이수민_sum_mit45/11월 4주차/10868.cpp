#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
 
int N, M;
vector<int> arr;
vector<int> Segment_Tree;
vector<pair<int, int>> cmd;
 
int Min(int A, int B) { 
    if (A < B) return A;
    return B; 
}

int Make_SegmentTree(int node, int start, int end){
    if (start == end){
        Segment_Tree[node] = arr[start];
        return Segment_Tree[node];
    }
 
    int mid = (start+end)/2;
    int left = Make_SegmentTree(node * 2, start, mid);
    int right = Make_SegmentTree(node * 2 + 1, mid + 1, end);
    Segment_Tree[node] = Min(left, right);
    
    return Segment_Tree[node];
}
 
int Query(int node, int start, int end, int left, int right){
    if (right < start || left > end) return 2e9;
    if (left <= start && end <= right) return Segment_Tree[node];
    
    int mid = (start + end) / 2;
    int Left_Result = Query(node * 2, start, mid, left, right);
    int Right_Result = Query(node * 2 + 1, mid + 1, end, left, right);
    return Min(Left_Result, Right_Result);
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        cmd.push_back(make_pair(a, b));
    }
    
    int Tree_Height = ceil(log2(N));
    int Tree_Size = (1 << (Tree_Height + 1));
    Segment_Tree.resize(Tree_Size);
 
    Make_SegmentTree(1, 0, N - 1);
    for (int i = 0; i < cmd.size(); i++){
        int idx = cmd[i].first - 1;
        int idx2 = cmd[i].second - 1;
        
        cout << Query(1, 0, N - 1, idx, idx2) << "\n";
    }
 
    return 0;
}
