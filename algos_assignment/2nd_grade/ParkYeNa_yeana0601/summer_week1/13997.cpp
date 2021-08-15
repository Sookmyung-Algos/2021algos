n,m=map(int,input().split())
arr=list(map(int,input().split()))

def part(x):
  mx=mn=arr[0]
  cnt=1
  for i in range(1,n):
    mx=max(mx,arr[i])
    mn=min(mn,arr[i])
    if mx - mn > x:
      cnt+=1
      mx=arr[i]
      mn=arr[i]
  return cnt

start, end, result = 0, max(arr), 0
while start<=end:
  mid=(start+end)//2
  if part(mid)<=m:
    end = mid-1
    result=mid
  else:
    start = mid+1
print(result)
