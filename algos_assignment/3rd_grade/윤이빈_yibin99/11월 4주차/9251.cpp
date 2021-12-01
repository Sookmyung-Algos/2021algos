#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int dp[1001][1001];

int main(){
    cin >> str1 >> str2;
    int l1 = str1.length();
    int l2 = str2.length();

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else{
                if(dp[i-1][j]<dp[i][j-1])
                    dp[i][j]=dp[i][j-1];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout << dp[l1][l2];
}
