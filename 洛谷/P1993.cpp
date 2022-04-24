#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=5e4;
const int INF=0x3f3f3f3f;
int n,m,next[maxn],edge[maxn],ver[maxn],head[maxn],cnt[maxn],v[maxn],dis[maxn],tot;
queue<int>q;
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
}
bool spfa()
{
	for(int i=0;i<=n;++i)
		dis[i]=INF;
	for(int i=0;i<=n;++i)
		v[i]=0;
	dis[0]=0,v[0]=1,cnt[0]=0;
	q.push(0);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		v[x]=0;
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i],z=edge[i];
			if(dis[y]>dis[x]+z)
			{
				dis[y]=dis[x]+z;
				cnt[y]++;
				if(cnt[y]>=n+1)
				return false;
				if(!v[y])q.push(y),v[y]=1;
			}
		}
	}
	return true;
}
int main() 
{
	scanf("%d%d",&n,&m);
	 while(m--) {
        int id, a, b, c;
        scanf("%d %d %d", &id, &a, &b);
        if(id != 3) scanf("%d", &c);
        switch(id) {
            case 1: add(a, b, -c); break;
            case 2: add(b, a, c); break;
            case 3: add(a, b, 0); add(b, a, 0);
        }
    }
	for(int i=1;i<=n;++i)
		add(0,i,0);
	if(spfa())printf("Yes");
	else printf("No");
	return 0;
}
