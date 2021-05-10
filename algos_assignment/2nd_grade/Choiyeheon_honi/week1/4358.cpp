#include <iostream>
#include <map>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string tree;
    float total=0;
    map<string,int> m;

    while (getline(cin,tree)){      //입력스트림으로 문자 읽어 tree 문자열에 저장, EOF에 도달하면 읽기 중지
        if (m.find(tree)!=m.end()){     //맵 내에 tree라는 키가 있는 경우
            m[tree]+=1;     //tree의 value 값 1 증가
        }
        else{               //없는 경우
            m[tree]=1;      //tree라는 키의 value 값은 1
        }
        total++;               //입력받는 나무 개수
    }
    
    cout << fixed;              //소수점을 고정시켜 표현
    cout.precision(4);          //소수점 4자리까지 표현
    
    for (auto it=m.begin();it!=m.end();it++){   //map의 beginning 반복자에서 1씩 증가하여 end 반복자가 아닐 때까지 반복
        float per=(it->second / total)*100;     //% = (종의 개수/전체 나무의 개수)*100
        cout<<(it->first)<<" "<<per<<'\n';      //key의 값과 해당하는 퍼센트를 한줄씩 출력
    }
}
