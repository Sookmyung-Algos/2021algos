#include <iostream>

using namespace std;

int parent[500000];
int n, m;
int result;

int Find(int x)
{
    if (x==parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
    
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        parent[x] = y;
        return false;
    }
    else
        return true;
}

int main()
{
    int from, to;

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    for (int i = 1; i <= m ; i++)
    {
   
        cin >> from >> to;
        
        if (Union(from, to))
        {
            result = i;
            break;
        }
    }

    if (result == 0)
        cout << 0;
    else
        cout << result;
}
