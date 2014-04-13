T = int(input())
for _ in range(T):
    line = [float(x) for x in input().strip().split()]
    C, F, X = line[0], line[1], line[2]
    answer, i, rate, time = X / 2.0, 1, 2, 0
    while True:
        time += C / rate
        rate += F
        if time + X / rate > answer:
            break
        answer = min(answer, time + X / rate)
    print("Case #%d: %.8f" % (_ + 1, answer))