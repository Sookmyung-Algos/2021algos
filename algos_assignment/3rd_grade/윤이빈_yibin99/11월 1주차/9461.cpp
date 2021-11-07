#include <iostream>
using namespace std;

int main() {
	long long int nums[101];
	nums[1]=1; nums[2]=1; nums[3]=1; nums[4]=2; nums[5]=2;
	for(int i=6;i<=100;i++){
		nums[i]=nums[i-1]+nums[i-5];
	}
	int t;
	cin >> t;
	while(t>0){
		int n;
		cin >> n;
		cout << nums[n] << "\n";
		t--;
	}
}
