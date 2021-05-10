#include <iostream>
using namespace std;

int main(){
    char stack[500001], num[500001];
    int sp=0;
    int n, k;
    cin >> n >> k;
    cin >> num;
    for(int i=0;i<n;i++){
        while(sp>0 && k>0){
            if(stack[sp-1]<num[i]){
                sp--;
                k--;
            }
            else break;
        }
        stack[sp++]=num[i];
    }
    while(k>0){
        sp--;
        k--;
    }
    for(int i=0;i<sp;i++){
        cout << stack[i];
    }
}
