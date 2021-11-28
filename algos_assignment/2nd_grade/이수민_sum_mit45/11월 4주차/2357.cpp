#include<iostream>
#include<vector>
#include<cmath>
#define MAX 100001
using namespace std;

int N, M;
int arr[MAX];
vector<int> min_tree, max_tree;

void init(int node, int start, int end){
  if(start == end){
    min_tree[node] = max_tree[node] = arr[start]; 
    return;
  }else{
    init(node*2, start, (start + end)/2 );
    init(node*2 +1 , (start + end)/2 +1, end);
    min_tree[node] = min(min_tree[node*2], min_tree[node*2 +1]); 
    max_tree[node] = max(max_tree[node*2], max_tree[node*2 +1]);
    return;
  }
}

pair<int,int> findMinMAx(int node, int start, int end, int left, int right){
  if(left >end || right < start ){
    return make_pair(INT32_MAX, 0);
  }else if(left <=start && end <= right){
    return make_pair(min_tree[node],max_tree[node]);
  }else{
    pair<int,int> l,r;
    l = findMinMAx(node*2, start,(start + end)/2 , left,right);
    r = findMinMAx(node*2 +1, (start + end)/2 +1, end , left,right);
    return make_pair(min(l.first, r.first),max(l.second, r.second));
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M;

  int h = (int)ceil(log2(N));
  min_tree = vector<int>(1<<(h+1));
  max_tree = vector<int>(1<<(h+1));

  for(int i=1; i<=N ; ++i)
    cin>>arr[i];

  init(1,1,N);
  int left,right;
  pair<int,int> result;
  while(M--){
    cin >> left >> right;
    result = findMinMAx(1, 1, N, left, right);
    cout << result.first << " " << result.second << "\n";
  }
  return 0;
}
