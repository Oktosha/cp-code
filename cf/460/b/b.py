k = int(input())
i = 0
j = 0
while j < k:
	i += 1
	x = sum(map(int, str(i)))
	if x == 10:
		j += 1
print(i)