from math import sqrt
T=int(input())
for _ in range(T):
	n=int(input())
	a=list(map(int,input().split()))
	def f(x):
		if x<=2:return 0
		return any(x%i==0 for i in range(2,(int)(sqrt(x))+1))
	if f(sum(a)):
		print(len(a))
		for i in range(n):
			print(i+1,end=' ')
		print()
		continue
	print(n-1)
	for i in range(n):
		if a[i]%2==1:
			for j in range(n):
				if j==i:continue
				print(j+1,end=' ')
			print()
			break