while 1:
	try:
		n = int(input())
		p = int(input())
		lo = 1
		hi = 10 ** 10
		while lo <= hi:
			mid = (lo + hi) // 2
			x = mid ** n
			if x == p:
				print(mid)
				break
			if x < p:
				lo = mid + 1
			else:
				hi = mid - 1
	except:
		break