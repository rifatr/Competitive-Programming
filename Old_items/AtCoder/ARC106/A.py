n = int(input())
f = 0
for i in range(1, 40):
  for j in range(1, 30):
    if (3**i)+(5**j) == n:
      f = 1
      a = i
      b = j
      break
  if f == 1:
     break
      
if f == 0:
  print(-1)
else:
  print(a, b, sep = " ")