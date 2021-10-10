#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>

#define INF 1e9
#define MAX 100000

using namespace std;

string S;
int N;

vector<string> arr[26];

bool dp[111];

int main() {

    cin >> S;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string ss;
    
        cin >> ss;
    
        int x = ss.back() - 'a';
        arr[x].push_back(ss);
    }

    dp[S.length()] = true;
        
    for (int i = S.length() - 1; i >= 0; i--) {
        if (!dp[i + 1]){
            continue;
        }
    
    int now = S[i] - 'a';

    for (auto it : arr[now]) {
        int L = it.length();
        int To = i - L + 1;
        
        if (To < 0){
            continue;
        }

        bool ok = true;
        
        for (int j = 0; j < L; ++j) {
            if (S[i - j] != it[(L - 1) - j]) {
                ok = false;
                break;
            }
        }
        
        if (ok){
            dp[To] = true;
        }
    }
}

    if (dp[0]){
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

}
