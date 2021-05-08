#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool strcpr(string str1, string str2)
{
    if (str1.size() == str2.size())
        return str1 < str2;
    else
        return str1.size() < str2.size();
}
int main()
{
    vector<string> v;
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        
        if(find(v.begin(), v.end(), str) == v.end()) //해당 단어가 존재하지 않을 경우 vector.end()를 반환
            v.push_back(str);
    }
    sort(v.begin(), v.end(), strcpr);
    
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
  
  return 0;
}
