#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> s;
	int cnt = 0;
	string key;
	while(getline(cin, key) && ++cnt){
		if (s.find(key) != s.end())
			++s[key];
		else
			s[key] = 1;
	}
	for(auto it = s.begin(); it != s.end(); ++it){
		cout << it->first << " ";
		printf("%.4lf\n", (double)it->second / cnt * 100);
	}
	return 0;
}
