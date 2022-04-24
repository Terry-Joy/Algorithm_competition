#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int N=2e5+10,M=2e6+10,INF=0x3f3f3f3f;
int head[N],ver[M],next1[M],hc[N],vc[M],nc[M],tc,tot,dcc,n,m;
int dfn[N],low[N],num,c[N],max_len,s,d[N];
bool bridge[M];
queue<int>q;

void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

void add_c(int x,int y)
{
    vc[++tc]=y,nc[tc]=hc[x],hc[x]=tc; 
}

void tarjan(int x,int in_edge)
{
    dfn[x]=low[x]=++num;
    for(int i=head[x];i;i=next1[i])
    {
        int y=ver[i];
        if(!dfn[y])
        {
            tarjan(y,i);
            low[x]=min(low[x],low[y]); 
            if(dfn[x]<low[y])
                bridge[i]=bridge[i^1]=1;
        } 
        else if(i!=(in_edge^1))
            low[x]=min(low[x],dfn[y]);
    } 
} 

int bfs(int x)
{
	for(int i=0;i<=dcc;++i)
		d[i]=INF;
	q.push(x);d[x]=0;
	while(q.size())
	{
		x=q.front();q.pop();
		for(int i=hc[x];i;i=nc[i])
		 	if(d[vc[i]]==INF)
		 		d[vc[i]]=d[x]+1,q.push(vc[i]); 
	}
	int k,y;
	for(k=y=1;k<=dcc;++k)
		if(d[k]>d[y])y=k;
	return y;
}

void dfs1(int x)
{
   c[x]=dcc;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(c[y]||bridge[i])continue;
      dfs1(y); 
   } 
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&(n|m))
    { 
        tot=1,tc=1,num=0;
        dcc=0;
        for(int i=0;i<=n;++i)
            head[i]=hc[i]=low[i]=dfn[i]=c[i]=0;
        for(int i=0;i<=2*m+1;++i)
        	bridge[i]=0;
        for(int i=1;i<=m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a); 
        }
        for(int i=1;i<=n;++i)
            if(!dfn[i])tarjan(i,0);
        for(int i=1;i<=n;++i)
        {
           if(!c[i])
           {
              dcc++;
              dfs1(i); 
           } 
        }
        for(int i=2;i<=tot;++i)
        {
            int x=ver[i],y=ver[i^1];
            if(c[x]==c[y])continue;
            add_c(c[x],c[y]);
        }
        s=bfs(1);
        s=bfs(s);
        printf("%d\n",dcc-1-d[s]);
    }
    return 0;
}
