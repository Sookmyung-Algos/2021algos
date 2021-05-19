#include <iostream>
#include <algorithm>

using namespace std;

int capacity[10001] = { 0 };
int N, C, M = 0;
int ans = 0;

struct info{
    int from;
    int to;
    int cnt;
} delivery[10000];

bool compare(info a, info b)
{
    if (a.to < b.to)
        return true;
    else if (a.to == b.to)
    {
        if (a.from < b.from)
            return true;
    }
    return false;
};
int main()
{
    cin >> N >> C;
    cin >> M;
    
    for (int i = 0; i < M; i++)
        cin >> delivery[i].from >> delivery[i].to >> delivery[i].cnt;
        
    sort(delivery, delivery + M, compare);
    
    for (int i = 0; i < M; i++)
    {
        int maxval = 0;
        for (int j = delivery[i].from; j < delivery[i].to; j++)
            maxval = max(capacity[j], maxval);
        
        for (int k = delivery[i].from; k < delivery[i].to; k++)
            capacity[k] += min(delivery[i].cnt, C - maxval);
        
        ans += min(delivery[i].cnt, C - maxval);
    }
    cout << ans << endl;
    return 0;
};
