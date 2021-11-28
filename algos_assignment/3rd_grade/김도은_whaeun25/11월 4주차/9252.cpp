#include <iostream>
#include <string>
#include <stack>

using namespace std;

int lcs[1001][1001];
string a, b;
stack<char> lcs_char;

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
    
    int i = la;
    int j = lb;
        
    while (i > 0 && j > 0){
        if (lcs[i][j] > lcs[i - 1][j - 1] && lcs[i][j] > lcs[i][j - 1] && lcs[i][j] > lcs[i - 1][j]){
            i = i - 1;
            j = j - 1;
            lcs_char.push(a[i]);
        }
        else if (lcs[i][j] == lcs[i][j - 1]){
                j = j - 1;
        }
        else{
            i = i - 1;
        }
    }
        
    while(!lcs_char.empty()){
        cout << lcs_char.top();
        lcs_char.pop();
    }
    
}

