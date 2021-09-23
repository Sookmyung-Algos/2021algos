import sys

def binary_search(num):
    left=0
    right=len(arr)
    while left<right:
        mid=(left+right)//2
        if arr[mid]<num:
            left=mid+1
        elif arr[mid]==num:
            return 1
        else:
            right=mid
    return 0

N=int(input())
arr=list(map(int,sys.stdin.readline().split()))
M=int(input())
b=list(map(int,sys.stdin.readline().split()))

arr.sort()

for i in range(M):
    print(binary_search(b[i]))
