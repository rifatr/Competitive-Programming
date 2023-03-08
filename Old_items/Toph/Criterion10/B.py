n = int(input())
p = (n * (n - 1))
k = 4
if p % k == 0:
	p = p // k
	k = 1
elif p % 2 == 0:
	p = p // 2
	k = 2
print(p, k, sep = " ")