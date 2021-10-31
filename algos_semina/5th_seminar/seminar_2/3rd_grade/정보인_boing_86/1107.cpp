#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

int n, m;
int MAX = 1000001;
bool b[10];

int check(int i){
	if(i == 0 && b[0] == false){
		return false;
	}

	while(i > 0){
		if(b[i%10] == false){
			return false;
		}
		i /= 10;
	}
	return true;
}

int from_brute(){
	int result = 987654321;
	int approx = 0;
	int length = 0;

	for(int i = 0; i<MAX; i++){
		if(check(i)){
			int button = abs(n-i);
			if(result > button){
				result = button;
				approx = i;
			}
		}
	}

	if(approx == 0){
		length = 1;
	}
	else{
		while(approx){
			approx = approx / 10;
			length++;
		}
	}
	cout<<result<<" "<<length<<endl;
	return result + length;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	memset(b, true, 10*sizeof(b[0]));
	for(int i = 0; i<m; i++){
		int broken;
		cin>>broken;
		b[broken] = false;
	}


	int from_100 = abs(n-100);
	int from_all = from_brute();

	//cout<<from_100<<endl;
	//cout<<from_all<<endl;
	cout<<min(from_100, from_all)<<endl;
} 
