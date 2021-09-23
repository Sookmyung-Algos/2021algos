#include <iostream>
#include <map>
#include <string>

using namespace std;

void init(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main(int args, const char* argv[]){
    init();
    map<string, float> dct;
    string tree;
    float per;
    int cnt = 0;

    while(getline(cin, tree)){
        if(dct.find(tree)!=dct.end()) dct[tree]++;
        else dct[tree] = 1;
        cnt++;
    }

    cout<<fixed; //소수점 고정하여 표현
    cout.precision(4); //소수점 아래 4자리까지

    for (auto a = dct.begin(); a!=dct.end();a++){
        per = a->second/cnt*100;
        cout << (a->first) << " " << per <<"\n";
    }

    return 0;
}  
