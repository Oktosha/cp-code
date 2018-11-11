c = [[0] * 10 for x in range(10)]
for i in range(10):
	c[i][0] = 1
	c[i][i] = 1
for i in range(10):
	print(c[i][0], end=" ")
	for j in range(1, i):
		c[i][j] = c[i - 1][j - 1] + c[i - 1][j]
		print(c[i][j], end=" ")
	print(c[i][i])