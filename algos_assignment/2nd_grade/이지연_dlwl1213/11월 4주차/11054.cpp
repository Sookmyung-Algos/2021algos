#include <cstdio>
using namespace std;

int get_max (int a, int b) { return a > b ? a : b; }
int main() {

    int N, i, j, max = 0;
    
    scanf("%d", &N);
    int arr[N+1];
    int dpi[N+1]; dpi[0] = 0;
    int dpd[N+2]; dpd[N+1] = 0;
    int dp[N+1];
    
    for (i = 1; i <= N; i++) scanf("%d", &arr[i]);

    for (i = 1; i <= N; i++) {
        dpi[i] = 1;
        dpd[N-i+1] = 1;
        for (j = 1; j < i; j++) {
            if ( arr[i] > arr[j] && dpi[j] + 1 > dpi[i]) dpi[i] = dpi[j] + 1;
            if ( arr[N-i+1] > arr[N-j+1] && dpd[N-j+1] + 1 > dpd[N-i+1]) dpd[N-i+1] = dpd[N-j+1] + 1;
        }
    }

    for (i = 1; i <= N; i++) {
        dp[i] = dpi[i] + dpd[i];
        max = get_max(max, dp[i]);
        
    }
    printf("%d\n", max-1);

    return 0;
}
