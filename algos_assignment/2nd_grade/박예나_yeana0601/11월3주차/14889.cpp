#include <iostream>
#include <cmath>
using namespace std;

int arr[20][20];
bool is_visited[20];
int n;
int ans = 1234567890;

void combination(int cnt, int cur){
    if(cnt == n/2){
        int a = 0, b = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(is_visited[i] && is_visited[j]){
                    a+= arr[i][j]; a+= arr[j][i];
                }else if(!is_visited[i] && !is_visited[j]){
                    b+= arr[i][j]; b+= arr[j][i];
                }
            }
        }
        ans = min(ans, abs(a-b));
    }
    for(int i=0; i<n; i++){
        if(is_visited[i]==false && i>cur){
            is_visited[i] = true;
            combination(cnt+1, i);
            is_visited[i] = false;
        }
    }
}
 
 
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> arr[i][j];
        }
    }
    combination(0,-1);
    cout <<ans<<"\n";
 
}

