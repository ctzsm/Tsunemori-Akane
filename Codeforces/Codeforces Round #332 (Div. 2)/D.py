x = int(input()) * 6
n, equ, ans = 0, False, []
while True:
	n += 1
	if n * (n + 1) * (2 * n - 1) > x:
		break
	if x % n != 0:
		continue
	if x % (n + 1) != 0:
		continue
	m = x // n // (n + 1) + n - 1
	if m % 3 != 0:
		continue
	m = m // 3
	if n <= m:
		ans.append((n, m))
		if n == m:
			equ = True
	else:
		break

print(len(ans) * 2 - equ)
for p in ans:
	print("%d %d" % (p[0], p[1]))
if equ:
	ans.pop()
ans.reverse()
for p in ans:
	print("%d %d" % (p[1], p[0]))
