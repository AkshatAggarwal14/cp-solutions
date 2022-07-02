n, x = [int(p) for p in input().split()]
a = [0] * n
b = [0] * n
for i in range(n):
    a[i], b[i] = [int(p) for p in input().split()]
res = float('inf')
sum = 0
for i in range(0, n):
    sum += a[i] + b[i]
    left = x - (i + 1)
    if left < 0:
        break
    res = min(res, sum + left * b[i])
print(res)