mod = 1000000007
a = []
a.append(1)
for i in range(1, 20000002):
	a.append((a[i - 1] * i) % mod)
for _ in range(int(input())):
	n = int(input())
	print((a[n - 1] * a[2 * n]) % mod)