def get_ans(x):
	l = len(str(x))
	for k in range(100 - l):
		small = 10 ** k
		big = 10 ** (k + l)
		t = x * (10 ** k)
		nearest_2 = 1
		ans = 0
		while nearest_2 < t:
			nearest_2 *= 2
			++ans
		extra = nearest_2 - t
		if extra < small or :
			return ans



for i in range(1000):
	print(2 ** i % 1000000)

n = int(input())
for i in range(n):
	x = int(input())
	print(get_ans(x))
	

