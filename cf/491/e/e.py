import math


def get_n_vars_when_amounts_fixed(a):
	# print("a", a)
	t = math.factorial(sum(a[1:]))
	for i in range(1, len(a)):
		t = t // math.factorial(a[i])

	for i in range(a[0]):
		# print(t)
		t *= (sum(a[1:]) + i);
	t //= math.factorial(a[0])
	# print("t", t)
	return t

def gen(a, b, pos):
	if pos == 10:
		return get_n_vars_when_amounts_fixed(b)

	if a[pos] == 0:
		b[pos] = 0
		return gen(a, b, pos + 1)

	ans = 0
	for i in range(1, a[pos] + 1):
		b[pos] = i
		ans += gen(a, b, pos + 1)

	return ans

a = [0] * 10
s = input()
for ch in s:
	a[int(ch)] += 1

# print(a)

b = [0] * 10
ans = gen(a, b, 0)

print(ans)

