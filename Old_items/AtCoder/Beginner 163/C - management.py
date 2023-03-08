x = [0] * int(input())

for i in input().split():
    x[int(i)-1] += 1

print(*x)
    
