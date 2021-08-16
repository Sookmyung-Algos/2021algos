#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int change(string a);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    map <string,int> st;
    map <string,int> en;        
    string S,E,Q;
    string time,name;
    int s,e,q;
    int cnt=0;
    
    cin>>S>>E>>Q;
    s=change(S);
    e=change(E);
    q=change(Q);
    
    while (!cin.eof()){
        cin>>time>>name;
        
        if (change(time)<=s)
            st[name]=1;
        else if(e<=change(time) && change(time)<=q)
            en[name]=1;
    }

    for (auto iter=st.begin();iter!=st.end();iter++){
        if (en.find(iter->first)!=en.end())
            cnt++;
    }
    cout<<cnt;
}

int change(string a){
    int result=1000*(a[0]-'0')+100*(a[1]-'0')+10*(a[3]-'0')+(a[4]-'0');
    return result;
}
