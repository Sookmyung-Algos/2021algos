#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>>v;
  
    for(int i=0, num; i<n; i++)
    {
        cin >> num;
        v.push_back(make_pair(i+1, num));
    }
    
    int index=0;
    int count=n;
    for(int i=0; i<count; i++)
    {
        cout << v[index].first << " ";
        int move = v[index].second;
        v.erase(v.begin()+index);
        
        if(--n==0) break;
        index=(move>0) ? index+(move-1) : n+(index+move)%n;
        index=index%n;
    }
    return 0;
}
