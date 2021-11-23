#include <iostream>
#include <string>
using namespace std;

int lcs[1001][1001];
string a, b;

int main() {
    int la, lb;
    cin >> a >> b;
    
    la = (int)a.size();
    lb = (int)b.size();

    for(int i = 1; i <= la; i++) {
        for(int j = 1; j <= lb; j++) {
            if(a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                if(lcs[i - 1][j] < lcs[i][j - 1]) {
                    lcs[i][j] = lcs[i][j - 1];
                } else {
                    lcs[i][j] = lcs[i - 1][j];
                }
            }
        }
    }

    cout << lcs[la][lb] << "\n";
    return 0;
}
