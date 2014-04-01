import fractions

maxN = 100000
isPrime = [True] * (maxN + 1)
isPrime[0] = isPrime[1] = False
prime = []
for i in range(2, maxN + 1):
    if isPrime[i]:
        for j in range(i + i, maxN + 1, i):
            isPrime[j] = False
        prime.append(i)

def check(x, l):
    rem, p, e = 0, 4, 10
    while l:
        if (l & 1) == 1:
            rem = (rem * e + p) % x
        p = (p * e + p) % x
        e = (e * e) % x
        l >>= 1
    return rem == 0

def solve(x):
    y = x
    c2, c5 = 0, 0
    while x % 2 == 0:
        c2 += 1
        x //= 2
    while x % 5 == 0:
        c5 += 1
        x //= 5
    zero = max(max(c2 - 2, 0), c5)
    p, c = [], []
    for i in range(len(prime)):
        if prime[i] * prime[i] > x or x <= 1:
            break
        if x % prime[i] == 0:
            cnt = 0
            p.append(prime[i])
            while x % prime[i] == 0:
                x //= prime[i]
                cnt += 1
            c.append(cnt)
    if x > 1:
        p.append(x)
        c.append(1)
    m = [0] * len(p)
    for i in range(0, len(p)):
        if p[i] == 3:
            m[i] = 3
            continue
        p1 = int(p[i] - 1)
        p2 = int(p1 ** 0.5)
        m[i] = p1
        flag = False
        for j in range(2, p2 + 1):
            if p1 % j == 0:
                flag = check(p[i], j)
                if flag:
                    m[i] = j
                    break
        if not flag:
            for j in range(p2 + 1, 1, -1):
                if p1 % j == 0:
                    flag = check(p[i], p1 // j)
                    if flag:
                        m[i] = p1 // j
                        break
    for i in range(len(p)):
        m[i] *= int(p[i]) ** int(c[i] - 1)
    four = 1
    if len(m) > 0:
        four = m[0]
    for i in range(1, len(p)):
        four = (four * m[i]) / fractions.gcd(four, m[i])
    return int(four) * 2 + zero

T = int(input())
for _ in range(T):
    x = int(input())
    print(solve(x))