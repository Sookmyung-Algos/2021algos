//9251 LCS

#include <iostream>
using namespace std;

int lcs[1001][1001];
string str1,str2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int str1_len,str2_len;
    cin >> str1 >> str2;
    
    str1_len = (int)str1.size();
    str2_len = (int)str2.size();
    
    for(int i=1;i<=str1_len;i++){
        for (int j=1;j<=str2_len;j++){
            if (str1[i-1] == str2[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            } else {
                if (lcs[i-1][j] < lcs[i][j-1]){
                    lcs[i][j] = lcs[i][j-1];
                } else {
                    lcs[i][j] = lcs[i-1][j];
                }
            }
        }
    }
    cout << lcs[str1_len][str2_len];
    return 0;
}
