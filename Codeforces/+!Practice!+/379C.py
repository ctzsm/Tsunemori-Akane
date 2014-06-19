import sys
n = int(input())
a = list(map(int, sys.stdin.read().split()))
g = sorted(range(n), key=lambda x: a[x])
for i in range(1, n):
	if a[g[i]] <= a[g[i - 1]]:
		a[g[i]] = a[g[i - 1]] + 1
print(' '.join(map(str, a)))