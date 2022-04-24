from math import comb,sqrt,ceil,floor
def f(n):
	a=(int)(floor(n-3*sqrt(n)))
	print(str(a+1)+" caonima")
	for i in range (a+1,n):
		for j in range(i+1,n):
			for k in range(j+1,n):
				for f in range(k+1,n):
					if(i*f==j*k):
						print(str(n)+": "+str(i)+" "+str(j)+" "+str(k)+" "+str(f))
for i in range(9,25):
	f(i)