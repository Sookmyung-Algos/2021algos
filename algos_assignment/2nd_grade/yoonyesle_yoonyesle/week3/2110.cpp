#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, x[200001], d, c, i, s, e, mid, ans, cnt, start;
	scanf("%d%d", &n, &c);
	for(i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x+n);
	s = 1; e = x[n-1] - x[0];
	while(s <= e){
		mid = (s + e) / 2;
		start = x[0];
		cnt = 1;
		for(i = 1; i < n; i++){
			d = x[i] - start;
			if(d >= mid){
				cnt++;
				start = x[i];
			}
		}
		if(cnt >= c){
			ans = mid;
			s = mid + 1;
		}
		else e = mid - 1; 
	}
	printf("%d", ans);
}
