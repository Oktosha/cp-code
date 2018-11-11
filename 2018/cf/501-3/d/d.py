n, k, s = map(int, input().split())
if s < k or k * (n - 1) < s:
    print("NO")
    exit()
print("YES")
cur_pos = 1
while s > k:
    delta = min(n - 1, s - (k - 1))
    s -= delta
    cur_pos += delta if cur_pos + delta <= n else -delta
    k -= 1
    print(cur_pos, end=" ")
while k > 0:
    cur_pos += 1 if cur_pos + 1 <= n else -1
    k -= 1
    print(cur_pos, end=" ")
print()