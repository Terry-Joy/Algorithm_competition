#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
int prime[1000],d[10000],cnt=0,sx,ex;
bool v[10002],vis[10000];
using namespace std;
void primes()
{
	v[1]=v[0]=1;
	for(int i=2;i<=10000;++i)
	{
		if(!v[i])prime[++cnt]=i;
		for(int j=1;prime[j]*i<=10000&&j<=cnt;++j)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}
bool check(int e)
{
	if(v[e])return 0;
	if(vis[e])return 0;
	return 1;
}
int bfs()
{
	queue<int>q;
	q.push(sx),d[sx]=0,vis[sx]=1;
	int num,y;
	while(q.size())
	{
		int x=q.front();q.pop();
		if(x==ex){return d[x];}
		 int t[5];
        t[1]=x/1000;   ///记录千位数
        t[2]=x/100%10;  ///记录百位数
        t[3]=x/10%10;   ///记录十位
        t[4]=x%10;   ///记录各位
      
		for(int i=1;i<=4;++i)
		{
			int temp=t[i];
			for(int j=0;j<10;++j)
			{
				if(t[i]!=j)
				{
					t[i]=j;
					num=t[1]*1000+t[2]*100+t[3]*10+t[4];
				}
				if(num>=1000&&num<=9999&&check(num))
				{
					q.push(num);
					d[num]=d[x]+1;
					vis[num]=1;
				}
			}
			t[i]=temp;
		}
	}
	return -1;
}
int main()
{
	primes();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		scanf("%d%d",&sx,&ex);
		int ans=bfs();
		if(ans!=-1)
		{
			printf("%d\n",ans);
		}
		else printf("Impossible\n");
	}
	return 0;
} 
