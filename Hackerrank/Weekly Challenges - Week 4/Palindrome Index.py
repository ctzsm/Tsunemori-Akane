import sys

T = int(input())
def check(s, idx):
    s = s[0:idx] + s[idx+1:len(s)]
    i, j = 0, len(s) - 1
    while i < j:
        if s[i] != s[j]:
            return False
        i, j = i + 1, j - 1
    return True
for _ in range(T):
    s = sys.stdin.readline().strip()
    n = len(s)
    i, j = 0, n - 1
    while i < j:
        if s[i] != s[j]:
            break
        i, j = i + 1, j - 1
    if i >= j:
        print(-1)
    elif check(s, i):
        print(i)
    else:
        print(j)