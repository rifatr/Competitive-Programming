n, m = map(int, input().split())
sum = 0
x = list(map(int, input().split()))

for i in range(m):
    sum = sum + x[i]

if sum > n :
    print(-1)
else:
    print(n - sum)
