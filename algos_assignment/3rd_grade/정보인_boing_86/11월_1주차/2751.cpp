#include <iostream>
#define inf 123456789;
using namespace std;

void merge(int* A, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1];
	int R[n2+1];

	for(int i = 0; i<n1; i++){
		L[i] = A[p+i];
	}

	for(int j = 0; j<n2; j++){
		R[j] = A[q+j+1];
	}

	L[n1] = inf;
	R[n2] = inf;

	int i = 0, j=0;

	while(i<n1 || j <n2){
		if(L[i] < R[j]){
			A[p+i+j] = L[i];
			i++;
		}
		else{
			A[p+i+j] = R[j];
			j++;
		}
	}
}

void mergeSort(int* A, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main() {
	cin.tie(NULL);
    ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int A[n];

	for(int i = 0; i<n; i++){
		cin>>A[i];
	}
	mergeSort(A, 0,n-1);

	for(int i = 0; i<n; i++){
		cout<<A[i]<<"\n";
	}
}
