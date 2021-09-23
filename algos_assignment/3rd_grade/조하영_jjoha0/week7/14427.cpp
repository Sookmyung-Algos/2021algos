#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> A;
vector <long long> tree;

int minIndex(int x, int y)
{
    if (A[x] == A[y])
        return x < y ? x : y;
    return A[x] < A[y] ? x : y;
}
int init(int node, int start, int end)
{
    if (start == end)
        return tree[node]= start;
    return tree[node] = minIndex(init(node*2,start,(start+end)/2),init(node*2+1,(start+end)/2+1,end));
}

int update(int node, int index, int start, int end)
{
    if (index < start || index > end || start == end)
        return tree[node];
    int mid = (start + end)/2;
    return tree[node] = minIndex(update(node*2, index, start, mid), update(node *2 + 1, index, mid+1, end));
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    int N, M;
    cin >> N;
    
    
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }
        
    int treeHeight = (int)ceil(log2(N));
    int treeSize = (1 << (treeHeight + 1));
    tree.resize(treeSize);

    init(1, 0, N-1);
    
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int query;
        cin >> query;
        if (query ==1)
        {
            int key, value;
            cin >> key >> value;
            
            A[key-1] = value;
            update(1, key, 0, N-1);
        }
        else
            cout << tree[1] + 1 << "\n";
    }
    return 0;
}
