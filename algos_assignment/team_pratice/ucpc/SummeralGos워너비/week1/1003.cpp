#include <cstdio>

using namespace std;

int dp[41] = {0, 1, 1};

int fibo(int n)
{
    
    for (int i = 3; i < 41; i++)
        dp[i] = dp[i-1] + dp[i-2];
        
    return dp[n];
}
int main(void)
{
   int TC;
   scanf("%d", &TC);
   
   int N;
   for (int i = 0; i < TC; i++)
   {
        scanf("%d", &N);
        
        if (N == 0)
            printf("%d %d\n", 1, 0);
        else if (N == 1)
            printf("%d %d\n", 0, 1);
        else
            printf("%d %d\n", fibo(N-1), fibo(N));
   }
   return 0;
}
