#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int cnt = 0;
	string name;
	map<string, int> m;
    
	while (getline(cin, name)) {
		if (m.find(name) == m.end())
			m[name] = 1;
		else m[name]++;
		cnt++;
	}
    
	for (auto i = m.begin(); i != m.end(); i++)
		cout << i->first << ' '
		<< fixed << setprecision(4) << ((float)i->second / cnt) * 100 << '\n';
        
	return 0;
}
