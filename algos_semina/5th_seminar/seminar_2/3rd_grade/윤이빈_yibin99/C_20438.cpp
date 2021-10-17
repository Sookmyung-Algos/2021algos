#include <iostream>
using namespace std;

int student[5003]={0, };
int sum[5003]={0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, q, m;
    cin >> n >> k >> q >> m;
    int s;
    for(int i=0;i<k;i++){
        cin >> s;
        student[s]=-1;
    }
    for(int i=0;i<q;i++){
        cin >> s;
        if(student[s]==-1) continue;
        for(int j=s;j<=n+2;j+=s){
            if(student[j]!=-1)
                student[j]=1;
        }
    }
    for(int i=3;i<=n+2;i++){
        if(student[i]!=1)
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
    for(int i=0;i<m;i++){
        int s, e;
        cin >> s >> e;
        int cnt=sum[e]-sum[s-1];
        cout << cnt << "\n";
    }
}
