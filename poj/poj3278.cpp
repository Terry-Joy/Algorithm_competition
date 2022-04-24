#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e5+10; 
int d[maxn],n,k;bool v[maxn];
void bfs()
{
	queue<int>q;
	v[n]=1,d[n]=0,q.push(n);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==k){printf("%d\n",d[k]);return;}
		int next;
		next=x+1;
		if(next<=100000&&next>=0&&!v[next])
		{
			d[next]=d[x]+1;
			v[next]=1;
			q.push(next);
		}
		next=x-1;
		if(next<=100000&&next>=0&&!v[next])
		{
			d[next]=d[x]+1;
			v[next]=1;
			q.push(next);
		}
		next=2*x;
		if(next<=100000&&next>=0&&!v[next])
		{
			d[next]=d[x]+1;
			v[next]=1;
			q.push(next);
		}
	}
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		if(n>k)printf("%d\n",n-k);
		else bfs();
	}
} 
