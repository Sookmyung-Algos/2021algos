#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
string s,t;
int a,b;
int arr1[10001];        //초반 순서
int arr2[10001];        //결과
int dp1[10001];         //두 동전 뺀 나머지 {...,2,2}
int dp2[10001];         //{2,2,...}

bool check1(void);      //앞에서부터 확인
bool check2(void);      //뒤에서부터 확인

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    cin>>s>>t;
    
    for (int i=0;i<n;i++){
        if (s[i]=='o')
            arr1[i]=0;
        else
            arr1[i]=1;
    }
    
    for (int i=0;i<n;i++){
        if (t[i]=='o')
            arr2[i]=0;
        else
            arr2[i]=1;
    }
    
    cin>>a>>b;      //두 동전
    
    int k1=0,k2=2;      //두 동전을 제외한 배열 순서 저장
    for (int i=0;i<a;i++,k1++,k2++){
        dp1[k1]=arr1[i];
        dp2[k2]=arr1[i];
    }
    for (int i=a+1;i<b;i++,k1++,k2++){
        dp1[k1]=arr1[i];
        dp2[k2]=arr1[i];
    }
    for (int i=b+1;i<n;i++,k1++,k2++){
        dp1[k1]=arr1[i];
        dp2[k2]=arr1[i];
    }
    dp1[n-2]=dp1[n-1]=dp2[0]=dp2[1]=2;
    
    bool check=true;
    for (int i=0;i<n;i++){
        if (arr1[i]!=arr2[i])
            check=false;
    }
    if (check){         //처음과 결과가 같은 경우 YES
        cout<<"YES";
        return 0;
    }
    
    if (check1()||check2()){
        cout<<"YES";
    }
    else
        cout<<"NO";
}

bool check1(void){
    
    bool flag1=false;
    bool flag2=false;
    int p=0,q=0;
    
    while (1){
        if (p==n)
            break;
        
        if (arr2[p]==dp1[q]){
            p++;
            q++;
            continue;
        }
        
        if (arr2[p]!=dp1[q]){
            if (!flag1){
                if (arr2[p]==arr1[a]){
                    p++;
                    flag1=true;
                    continue;
                }
                
                else{
                    return false;
                }
            }
            
            else if (flag1 && !flag2){
                if (arr2[p]==arr1[b]){
                    p++;
                    flag2=true;
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

bool check2(void){
    bool flag1=false;
    bool flag2=false;
    int p=n-1,q=n-1;
    
    while (1){
        if (p==-1)
            break;
        
        if (arr2[p]==dp2[q]){
            p--;
            q--;
            continue;
        }
        
        if (arr2[p]!=dp2[q]){
            if (!flag2){
                if (arr2[p]==arr1[b]){
                    p--;
                    flag2=true;
                    continue;
                }
                
                else{
                    return false;
                }
            }
            
            else if (!flag1 && flag2){
                if (arr2[p]==arr1[a]){
                    p--;
                    flag1=true;
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}
