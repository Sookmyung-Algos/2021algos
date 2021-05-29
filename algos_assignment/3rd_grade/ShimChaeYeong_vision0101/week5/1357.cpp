#include <iostream>
#include <queue>
using namespace std;
int arr[4] = {1000, 100, 10, 1};
int arr2[4] = {1, 10, 100, 1000};
int sum = 0;
int check = 0;

int REV(int num){
    
    sum = 0;
    int j = 0;
    queue<int> Q;
    for(int i=0; i<4; i++){
        Q.push(num / arr[i]);
        num = num-(num/arr[i]) * arr[i]; 
    }
    for(int i=0; i<4; i++){
        check = Q.front();
        if(check!=0){
            sum += check * arr2[j];
            j++;
        }
        Q.pop();
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y;
    cin >> X >> Y;
    cout << REV(REV(X)+REV(Y));
 
}
