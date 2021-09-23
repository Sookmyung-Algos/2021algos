//1339 단어수학

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
int alpha[26];
vector<string> V;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string Inp; 
        cin >> Inp;
        V.push_back(Inp);
    }

    for (int i = 0; i < N; i++)
    {
        string S = V[i];
        int len = S.length();
        int pow = 1;

        for (int j = len - 1; j >= 0; j--)
        {
            int tmp = S[j] - 'A';
            alpha[tmp] = alpha[tmp] + pow;
            pow = pow * 10;
        }
    }
    sort(alpha, alpha + 26,greater<>());    // 내림차순

    int ans = 0;
    int num = 9;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0) break;
        ans = ans + (alpha[i] * num);
        num--;
    }

    cout << ans << '\n';
    
    return 0;
}
