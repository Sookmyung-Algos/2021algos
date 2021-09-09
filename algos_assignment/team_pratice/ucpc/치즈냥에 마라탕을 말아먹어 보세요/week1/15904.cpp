#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
	string str;
	string answer="";
	string ucpc="UCPC";
	int cnt=0;
	getline(cin, str);
	for(int i=0;i<str.size();i++){
		if(str[i]==ucpc[cnt]){
			cnt++;
		}
	}
	answer=(cnt==4)?"I love UCPC":"I hate UCPC";
	cout<<answer<<endl;
	return 0;

}
