n = int(input())
a = set(map(int, input().split()))
print(len(a.difference({0})))
