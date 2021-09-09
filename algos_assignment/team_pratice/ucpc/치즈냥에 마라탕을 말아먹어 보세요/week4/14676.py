import sys
from sys import stdin
n, m, k = map(int, stdin.readline().split())
arr = [[] for i in range(n+1)]
build = [0] * (n+1)
indegree = [0] * (n+1)
for i in range(m):
	f, s = map(int, stdin.readline().split())
	arr[f].append(s)
	indegree[s] += 1
 
for i in range(k):
	command, building = map(int, stdin.readline().split())
	if command == 1:
		if indegree[building]:
			print("Lier!")
			sys.exit(0)
		build[building] += 1
		if build[building] == 1:
			for j in arr[building]:
				indegree[j] -= 1
 
	else:
		if build[building] <= 0:
			print("Lier!")
			sys.exit(0)
		build[building] -= 1
		if not build[building]:
			for j in arr[building]:
				indegree[j] += 1
 
print("King-God-Emperor")
