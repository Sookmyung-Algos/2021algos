#include <iostream>

using namespace std;
int n;
long long arr[36];

void Recurrence(void){
        arr[0] = 1;
        for (int i = 1; i < 36; i++){
			for (int j = 0; j <= i - 1; j++){
				arr[i] += arr[j] * arr[i - 1 - j];
			}       
		}
}


int main(){
	
	cin >> n;
	
	Recurrence();
	cout << arr[n];
	
	return 0;
}
