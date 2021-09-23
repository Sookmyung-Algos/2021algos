#include <iostream>
#include <cctype>
#include <deque>
#include <string>
using namespace std;

long long cal(long long a,long long b,char x);
int sol(char a);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    deque <char> dq;
    deque <long long> n;
    string x;
    bool check=true;
    long long temp,op1,op2;
    
    cin>>x;
    
    if (x[0]=='-')
        check=false;
    
    for (int i=0;i<x.size();i++){
        long long num=0;
        
        if (!isdigit(x[i]))
            dq.push_back(x[i]);
        
        else {
            if (x[i]=='0'){
                if (!isdigit(x[i+1])){
                    n.push_back(0);
                    continue;
                }
                while (x[i+1]=='0')
                    i++;
            }
            while (isdigit(x[i])){
                num=num*10+(x[i]-'0');
                i++;
            }
            n.push_back(num);
            i--;
        }
    }
    if (!check){
        op1=n.front();
        n.pop_front();
        n.push_front(-op1);
        dq.pop_front();
    }
    
    while (!dq.empty()){
        if (sol(dq.front())>sol(dq.back())){
            op1=n.front();
            n.pop_front();
            op2=n.front();
            n.pop_front();
            temp=dq.front();
            dq.pop_front();
            n.push_front(cal(op1,op2,temp));
        }
        
        else if (sol(dq.front())<sol(dq.back())){
            op1=n.back();
            n.pop_back();
            op2=n.back();
            n.pop_back();
            temp=dq.back();
            dq.pop_back();
            n.push_back(cal(op2,op1,temp));
        }
        
        else{
            long long sum1=cal(n[0],n[1],dq[0]);
            long long sum2=cal(n[n.size()-2],n[n.size()-1],dq[dq.size()-1]);
            
            if (sum1>=sum2){
                op1=n.front();
                n.pop_front();
                op2=n.front();
                n.pop_front();
                temp=dq.front();
                dq.pop_front();
                n.push_front(cal(op1,op2,temp));
            }
            
            else{
                op1=n.back();
                n.pop_back();
                op2=n.back();
                n.pop_back();
                temp=dq.back();
                dq.pop_back();
                n.push_back(cal(op2,op1,temp));
            }
        }
    }
    cout<<n[0];
}


long long cal(long long a,long long b,char x){
    if (x=='+')
        return a+b;
    
    else if (x=='*')
        return a*b;
    
    else if (x=='-')
        return a-b;
    
    else if (x=='/')
        return a/b;
    
    return -1;
}

int sol(char a){
    if (a=='*' || a=='/')
        return 2;
    else
        return 1;
}
