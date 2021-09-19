#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 234567899

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int n, k;
		vector <int> v;
		cin>>n>>k;
		for(int i = 0; i<n; i++){
			int tmp;
			cin>>tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());

		int n1 = 0;
		int n2 = n-1;
		int ans = 0;
		int min = MAX;

		while(n1 < n2){
			int sum = v[n1] + v[n2];
			if(sum == k){
				n1++;
				n2--;
			}
			else if(sum < k){
				n1++;
			}

			else{
				n2--;
			}
			int a = abs(sum-k);
			if(a < min){
				min = a;
				ans = 1;
			}
			else if(a == min){
				ans++;
			}
		}
		cout<<ans<<endl;
	}

}
