T = int(input())
for _ in range(T):
    s = input().strip()
    ans = 0
    for i in range(0, len(s) // 2):
        ans += abs(ord(s[i]) - ord(s[len(s) - i - 1]))
    print(ans)