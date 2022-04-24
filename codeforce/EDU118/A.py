import math
t=int(input())
for i in range(t):
	a,b=map(int,input().split())
	c,d=map(int,input().split())
	a=math.log(a/c,10)
	if a>(d-b):
		print('>')
	elif a<(d-b):
		print('<')
	else:
		print('=')