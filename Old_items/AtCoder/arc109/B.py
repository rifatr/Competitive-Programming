n = int(input())
l = 0
h = n + 1
m = 0
ans = 0
while h - l > 1:
	m = (l + h) // 2
	d = (m * (m + 1)) // 2
	if d > n + 1:
		h = m
	else:
		l = m
		#ans = max(ans, m)
	#print(l, h, m, d, ans, sep = " ")
print(n + 1 - l)
