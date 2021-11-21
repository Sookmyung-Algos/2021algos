#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 110

using namespace std;

int main(){
    
    int n, m;
    double total;
    
    while (1) {
        
        scanf("%d %lf", &n, &total);
        
        if (!n) {
          break;
        }
        
        m = int(total * 100.0 + 0.5);
        
        vector<int> dp(m+1, -1);
        
        dp[0] = 0;
        
        while (n--) {
            
          int calorie, money;
            
          scanf("%d %lf", &calorie, &total);
            
          money = int(total * 100.0 + 0.5);
            
          for (int i = 0; i <= m - money; ++i) {
            if (0 <= dp[i]) {
              dp[i + money] = max(dp[i + money], dp[i] + calorie);
            }
          }
        }
        
        int answer = 0;
        
        for (int i = 0; i <= m; ++i) {
          answer = max(answer, dp[i]);
        }
        
        printf("%d\n", answer);
        
      }
}
