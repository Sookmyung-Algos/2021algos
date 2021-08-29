#include<iostream>

int b[1000000];

//두 배열의 합병 
void merge(int a[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	
	//a의 합병 
	while(i<=mid && j<=right) {
		if(a[i]<=a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	
	// 한쪽 부분에 남은 값들 복사 
	if(i>mid) {
		for(l = j; l <= right; l++)
			b[k++] = a[l];
	}
	else {
		for(l = i; l <= mid; l++)
			b[k++] = a[l];
	}
	
	//인자로 온 배열에 값 복사 
	for(l = left; l<=right; l++)
		a[l] = b[l];
}

//합병 정렬 
void merge_sort(int a[], int left, int right) {
	int mid;
	
	if(left < right) {
		mid = (left+right)/2;
		merge_sort(a, left, mid); //분할 
		merge_sort(a,mid+1, right); //분할 
		merge(a, left,mid,right);
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	int a[N];
	
	for (int i = 0; i < N; i++)
		std::cin>>a[i];
	
	merge_sort(a, 0, N-1);
	
	for(auto n: a)
		std::cout<<n<<'\n';
		
	return 0;
}
