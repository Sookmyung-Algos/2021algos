#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1000;
int n, i; // 사람의 수, 시간
int p[MAX];
int main(void){
    cin >> n;
    for(int i =0; i<n ;i++){
    	cin >> p[i];	
	}
	
	sort(p, p+n); // 시간이 짧은 사람부터로 정렬
  
  int sum = 0;
	for(int i =0; i<n ;i++){
    	sum += p[i]*(n-i); // 전체 걸리는 시간 합
	}
	
	cout << sum << endl;
	return 0;
}
 
