#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    int num;
    int arr[1001] = {};
    int arr2[1001]= {};
    int i=0;
    int max = 0;
    float sum = 0;
    
    cin >> count; // 수가 몇개인지
    for(int i=0; i<count; i++){
        cin >> arr[i];
        if(arr[i] > max) max = arr[i];        
    }

    for(int i=0; i<count; i++){
        sum +=  (float)arr[i] / max * 100;
    }

    cout << (float) (sum / count);
}
