#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int n, idx = 1;
    ll tmp = 0;
    queue<ll> q;
    cin >> n;

    for(int i = 1; i <= 9; i++)
        q.push(i);

    while(idx <= n)
    {
        if(q.empty())
        {
            tmp =- 1;
            break;
        }
        tmp = q.front();
        q.pop();
        int m = tmp % 10;
        for(int i = 0; i < m; i++)
            q.push(tmp * 10 + i);

        idx++;
    }

    printf("%lld", tmp);
    
    return 0;
}
