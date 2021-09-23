#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;

vector <ll> arr;
vector <ll> temp;
vector <ll> v[100001];          //격려의 가짓수 저장하는 벡터배열
ll comb[6];
ll n,k,c;
ll cnt=0;

void dfs(ll index,ll num);
bool check(ll min,ll index);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll a;
    ll sum=0;
    cin>>n>>k>>c;
    for (int i=0;i<n;i++){      //요리사 음식 조리시간
        cin>>a;
        arr.push_back(a);
        sum+=a;
    }
    
    if (sum-arr.size()<=c){     //모두 1로 바꿀 수 있는 경우
        ll time=1;
        while (arr.size()*time<k)
            time++;
        cout<<time;
        return 0;
    }
    
    temp=arr;
    dfs(0,0);           //격려의 가짓수 저장
    
    //이분탐색(시간)
    ll s=0;
    ll e=1000000000000;
    ll result;
    while (s<=e){
        bool flag=false;
        ll mid=(s+e)/2;
        for (int i=0;i<cnt;i++){
            if (check(mid,i)){      //시간안에 k개의 음식을 만들 수 있는 경우
                flag=true;
                break;
            }
        }
        
        if (flag){      //만들 수 있는 경우 -> 시간이 작은 부분에서 다시 탐색
            result=mid;
            e=mid-1;
        }
        else        //만들 수 없는 경우 -> 시간이 큰 부분에서 다시 탐색
            s=mid+1;
    }
    cout<<result<<'\n';
    
}

void dfs(ll index,ll num){          //중복조합(백트래킹)
    if (num==c){
        bool check=true;
        for (int i=0;i<arr.size();i++){
            for(int j=0;j<num;j++){
                ll x=i;
                if(x==comb[j]){      //격려의 경우에 들어가는 경우
                    check=false;
                    break;
                }
            }
            if (check)
                v[cnt].push_back(arr[i]);
            else
                v[cnt].push_back(temp[i]);      //격려된 값으로 저장
        }
        cnt++;
        return;
    }
    
    for (ll i=index;i<arr.size();i++){
        if (temp[i]==1)
            continue;
        comb[num]=i;
        temp[i]--;
        dfs(i,num+1);
        temp[i]++;
    }
}

bool check(ll min,ll index){        //해당 시간 안에 k개의 음식이 조리되는지 확인
    ll cnt=0;
    for (int i=0;i<v[index].size();i++){
        cnt+=(min/v[index][i]);
    }
    if (cnt>=k)
        return true;
    return false;
}
