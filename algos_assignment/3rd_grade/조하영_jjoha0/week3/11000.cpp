#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    pair<int, int> c[200001];
    
    for (int i = 0; i < N; i++)
        cin >> c[i].first >> c[i].second;
        
    sort(c, c + N);
    
    pq.push(c[0].second);
    
    for (int i = 1; i < N; i++)\
    {
        if(pq.top() <= c[i].first)
        {
            pq.pop();
            pq.push(c[i].second);
        }
        else
            pq.push(c[i].second);
    }
    
    cout << pq.size() << endl;
    
    return 0;
}
