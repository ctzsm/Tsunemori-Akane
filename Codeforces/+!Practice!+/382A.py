[left, right] = input().split('|')
weight = input().strip()
l, r, w = len(left), len(right), len(weight)
d = abs(l - r)
if w < d or (w - d) % 2 == 1:
	print("Impossible")
else:
	if l < r:
		left = left + weight[:d]
	else:
		right = right + weight[:d]
	weight = weight[d:]
	d = len(weight)
	print(left+weight[:d//2]+"|"+right+weight[d//2:])