inp = [int(x) for x in input().split()]
A, B, N = inp[0], inp[1], inp[2]
C = 0
for i in range(3, N + 1):
	C = B * B + A
	A = B
	B = C
print(C)