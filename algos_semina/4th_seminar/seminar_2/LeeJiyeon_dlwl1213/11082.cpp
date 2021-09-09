#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num;
string ques;

ll GCD(ll x, ll y){
	if(y==0) return x;
	return GCD(y, x%y);
}

void makeans(string A){
	int SS = A.size();
	// 분자 
	ll BoonJa = 0LL;
  
	int idx = 2;
  
	while(1){
		if(idx==SS) break;
		if(A[idx]=='(') break;
		BoonJa = BoonJa*10+(A[idx]-'0');
		idx++;
	}
  
	int cnt = idx-2;

	int cnt2 = 0; 

	if(idx!=SS){
		ll temp2 = BoonJa;
    
		while(1){
			idx++;
			if(A[idx]==')') break;	
			BoonJa = BoonJa*10+(A[idx]-'0');
			cnt2++;
		}
    
		if(BoonJa!=temp2) BoonJa -= temp2;
	}
 
	ll BoonMo = 0LL;

	while(cnt2--) 
    BoonMo = BoonMo*10+9;
  
	if(BoonMo == 0LL) 
    BoonMo = 1LL;

	while(cnt--) 
    BoonMo*=10;
  
	ll G = GCD(BoonMo, BoonJa);
	cout << BoonJa/G << '/' << BoonMo/G << '\n';
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 
  cin >> num;
  while(num--){
	  cin >> ques;
	  makeans(ques);
  }
  return 0;
}
