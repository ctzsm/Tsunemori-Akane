T = int(raw_input())


def check(t, M, N):
    res = 0
    for x in M:
        res += (t - 1) / x + 1
    return res >= N

for _ in range(T):
    [B, N] = [int(x) for x in raw_input().split()]
    M = [int(x) for x in raw_input().split()]
    if N <= B:
        print("Case #%d: %d" % (_ + 1, N))
        continue
    ans, t = 0, 1
    while not check(t, M, N):
        t *= 2
    l, r = 0, t
    while l < r:
        mid = (l + r) / 2
        if check(mid, M, N):
            r = mid
        else:
            l = mid + 1
    s = 0
    for x in M:
        if (l - 1) % x != 0:
            s += (l - 1) / x + 1
        else:
            s += (l - 1) / x
    for i in range(len(M)):
        if (l - 1) % M[i] == 0:
            s += 1
            if s >= N:
                ans = i + 1
                break
    print("Case #%d: %d" % (_ + 1, ans))
