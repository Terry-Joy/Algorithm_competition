def solve():
	n,m=map(int,input().split())
	res=[0 for i in range(n+1)]
	for _ in range(m):
		a,b,c=map(int,input().split())
		res[b]=1
	for i in range(1,n+1):
		if res[i]==0:
			for j in range(1,n+1):
				if j==i: continue
				print(j,i)
			return


if __name__=="__main__":
	t=int(input())
	for _ in range(t):
		solve()