n = int(input())
ans = 0
for i in range(65):
	if 2**i > n:
		ans = i
		break
print(ans - 1)