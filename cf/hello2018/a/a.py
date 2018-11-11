n = int(input())
m = int(input())
if n > 40:
	print(m)
else:
	print(m % (1 << n))