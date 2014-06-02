# need Miller-Rabin
T = int(input())
M = 10 ** 6
isPrime = [True for i in range(M + 1)]
isPrime[0] = isPrime[1] = False
prime = []
for i in range(2, M + 1):
    if isPrime[i]:
        prime.append(i)
        for j in range(i + i, M + 1, i):
            isPrime[j] = False
            
def checkPrime(x):
    if x <= M:
        return isPrime[x]
    else:
        for p in prime:
            if x % p == 0:
                return False
    return True

def output(out):
    if out:
        print("Yes")
    else:
        print("No")
        
for _ in range(T):
    line = input().strip().split()
    N, K = int(line[0]), int(line[1])
    if N < K * 2:
        output(False)
        continue
    if K == 1:
        output(checkPrime(N))
        continue
    if K == 2 and N % 2 == 1:
        output(checkPrime(N - 2))
        continue
    output(True)