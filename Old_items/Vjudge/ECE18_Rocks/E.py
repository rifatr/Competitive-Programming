def cnt(x):
	d = 0
	while x > 0:
		d += 1
		x = x // 10
	return d

for _ in range(int(input())):
	l = int(input())
	a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
	s = 2
	print(2, end = " ")
	for i in range(2, l + 1):
		for j in a:
			if cnt(s * j) == i:
				print(j, end = " ")
				s *= j
				break

	print ("")