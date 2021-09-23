#include <iostream>
#include <stack>

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main(int args, const char* argv[]) {
    init();
    int n; cin >> n;
    string word;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        stack<char> wordStk;
        cin >> word;

        for (int j = 0; j < word.length(); j++) {
            if (wordStk.empty()) wordStk.push(word[j]);
            else {
                if (wordStk.top() == word[j]) wordStk.pop();
                else wordStk.push(word[j]);
            }
        }
        if (wordStk.empty()) cnt++;
    }
    cout << cnt;
    return 0;
}
