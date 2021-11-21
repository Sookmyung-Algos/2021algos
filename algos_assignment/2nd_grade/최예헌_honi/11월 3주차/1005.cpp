#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    int n,k;
    int x,y,w;
    
    cin>>t;
    while (t--){
        vector <int> v[1001];
        int arr[1001]={0,};
        int topo[1001]={0,};
        int dp[1001];
        queue <int> q;
        
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        
        for (int i=0;i<k;i++){
            cin>>x>>y;
            v[x].push_back(y);
            topo[y]++;
        }
        
        cin>>w;
        for (int i=1;i<=n;i++){
            dp[i]=arr[i];
            if (topo[i]==0)
                q.push(i);
        }
        
        while (!q.empty()){
            int temp=q.front();
            q.pop();
            
            for (int i=0;i<v[temp].size();i++){
                dp[v[temp][i]]=max(dp[v[temp][i]],dp[temp]+arr[v[temp][i]]);
                
                if (topo[v[temp][i]]>0)
                    topo[v[temp][i]]--;
                if (topo[v[temp][i]]==0)
                    q.push(v[temp][i]);
            }
        }
        
        cout<<dp[w]<<'\n';
    }
}
