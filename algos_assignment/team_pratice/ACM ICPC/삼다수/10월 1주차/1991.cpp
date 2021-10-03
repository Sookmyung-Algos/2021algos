#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct node{
	char left;
	char right;
};
vector <node> v(27);

void pre(char n){
	if( n == '.'){
		return ;
	}
	cout<<n;
	pre(v[n].left);
	pre(v[n].right);
}
void inO(char n){
	if( n == '.'){
		return ;
	}

	inO(v[n].left);
	cout<<n;
	inO(v[n].right);
}

void post(char n){
	if( n == '.'){
		return ;
	}

	post(v[n].left);
	post(v[n].right);
	cout<<n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  for(int i = 0; i<n; i++){
	  char a, b, c;
	  cin>>a>>b>>c;
	  v[a].left = b;
	  v[a].right = c;
  }

  pre(65); //A
  cout<<"\n";
  inO(65);//A
  cout<<"\n";
  post(65);//A
}
