#include<iostream> 
#include<string> 
#include<vector> 
using namespace std; 

vector<int> getPi(string pattern)
{
    vector<int> pi(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i <pi.size(); i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j-1];
            
        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
    return pi;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int L;
    string pattern;
    
    cin >> L;
    cin >> pattern;
    
    vector<int>pi = getPi(pattern);
    cout << L - pi[L-1];
    
    return 0;
}
