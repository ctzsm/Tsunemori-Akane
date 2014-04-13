T = int(input())
for _ in range(T):
    N = int(input())
    nao = sorted([float(x) for x in input().strip().split()])
    ken = sorted([float(x) for x in input().strip().split()])
    answer1, answer2 = 0, 0
    i1, j1, i2, j2 = 0, N - 1, 0, N - 1
    while i1 <= j1 and i2 <= j2:
        if nao[i1] < ken[i2]:
            i1, j2 = i1 + 1, j2 - 1
        else:
            answer1 += 1
            i1, i2 = i1 + 1, i2 + 1
    v = [False] * N
    i2 = 0
    for i in range(N - 1, -1, -1):
        flag = False
        for j in range(0, N):
            if v[j]:
                continue
            if ken[j] > nao[i]:
                v[j], flag = True, True
                answer2 += 1
                break
        if not flag:
            v[i2] = True
            i2 += 1
    answer2 = N - answer2
    print("Case #%d: %d %d" % (_ + 1, answer1, answer2))
