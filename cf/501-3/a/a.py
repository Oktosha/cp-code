n, m = map(int, input().split())
a = [0] * m
for i in range(n):
    l, r = map(int, input().split())
    for j in range(l - 1, r):
        a[j] += 1

print(a.count(0))
for i in range(m):
    if a[i] == 0:
        print(i + 1, end=" ")
print()