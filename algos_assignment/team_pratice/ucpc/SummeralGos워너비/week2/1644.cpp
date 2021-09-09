#include <iostream>
#include<vector>

using namespace std;

int N, sum;
vector<bool> flag;
vector<int> prime;
int main()
{
    cin >> N;
    flag.resize(N+1, true);
    
    for (int i = 2; i * i <= N; i++)
    {
        if (flag[i] == true)
        {
            for (int j = 2*i; j <= N; j = j + i)
                flag[j] = false;
        }
        
    }
    for (int i = 2; i <= N; i++)
    {
        if (flag[i] == true)
        {
            prime.push_back(i);
        }
    }
    
    int s = 0;
    int e = 0;
    int cnt = 0;
    int sum = 0;
    while (1)
    {
        if (sum > N)
        {
            sum -= prime[s];
            s++;
        }
            
        else if (sum < N)
        {
            if (e >= prime.size())
                break;
            sum += prime[e];
            e++;
        }
        
        else
        {
            cnt++;
            if (e >= prime.size())
                break;
            sum += prime[e];
            e++;
        }
    }
    cout << cnt;
    return 0;
}
