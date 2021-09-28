#include <iostream>
using namespace std;


int main() {
    int arr[5];
    for (int i=0;i<5;i++){
        cin >> arr[i];
    }
    
    int number=1;
    while (1){
        int cnt=0;
        for (int i=0;i<5;i++){
            if (number % arr[i]==0) cnt++;
            
        }
        if (cnt >=3){
            cout << number << '\n';
            break;
        }
        number++;
    }
    return 0;
}
