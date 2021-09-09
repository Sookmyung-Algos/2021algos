#include <iostream>
#include <deque>
using namespace std;

deque<int> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    arr.resize(n);
    int order[n+1];
    for(int i=0;i<n;i++)
        arr[i]=i+1;
    int cnt=0, dir=0, num=0;
    while(cnt<n){
        if(dir==0){
            for(int i=0;i<k;i++){
                arr.push_back(arr.front());
                arr.pop_front();
            }
            num=arr.back();
            arr.pop_back();
        }
        else{
            for(int i=0;i<k;i++){
                arr.push_front(arr.back());
                arr.pop_back();
            }
            num=arr.front();
            arr.pop_front();
        }
        order[cnt++]=num;
        if(cnt%m==0)
            dir=(dir==1?0:1);
    }
    for(int i=0;i<n;i++)
        cout << order[i] << "\n";
}
