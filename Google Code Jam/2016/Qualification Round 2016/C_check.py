for _ in range(501):
	x = input().split()
	if _ == 0:
		continue
	n, d = x[0], [int(y) for y in x[1:]]
	f = True
	print(n, len(n))
	for b in range(2, 11):
		nn = int(n, b)
		if nn == d[b - 2] or nn % d[b - 2] != 0:
			f = False
			break
	if not f:
		print("NO")
		break
print("YES")
