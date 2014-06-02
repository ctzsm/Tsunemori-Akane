M = 10 ** 9 + 7
N = input().strip()
S, B, answer = 0, 1, 0
for i in range(len(N) - 1, -1, -1):
    answer = (answer + int(N[i]) * B * (i + 1)) % M
    S -= int(N[i])
    B = (B * 10 + 1) % M
print(answer)