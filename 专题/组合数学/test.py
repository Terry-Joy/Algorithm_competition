from scipy.special import comb
mod=1e9+7
d=[0]*10005
def init():
	d[0]=d[2]=1
	for i in range(3,10001):
		d[i]=(i-1)*(d[i-1]+d[i-2])%mod

def f(n,m):
	return comb(n,m)*d[n-m]%mod

init()
t=int(input())
for i in range(t):
	a,b=map(int,input().split(' '))
	if(a==b):
		print(1)
	else:
		print(((int)(f(a,b)))%mod)