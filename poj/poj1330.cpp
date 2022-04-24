#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20100,de=30;
int head[N],next1[2*N],ver[2*N],f[N][de],deg[N],t,n,m,d[N],tot=0,lg[N];
void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
    d[now]=d[fa]+1;
    f[now][0]=fa;
    for(int i=1;i<=lg[d[now]];++i)
        f[now][i]=f[f[now][i-1]][i-1];
    for(int i=head[now];i;i=next1[i])
    {
        if(ver[i]!=fa)	
            dfs(ver[i],now); 
    }
}
int lca(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])
    	x=f[x][lg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int i=lg[d[y]]-1;i>=0;--i)
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=20000;++i)
    	lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    while(t--)
    {
        tot=0;
        scanf("%d",&n);
        for(int i=0;i<=n;++i)
            head[i]=0,d[i]=0,deg[i]=0;
        for(int i=1;i<n;++i) 
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            deg[b]++;
        }
        int k=1;
        for(int j=1;j<=n;++j)
        {
            if(!deg[j])
                k=j;
        }
        dfs(k,0);
        int q1,q2;
        scanf("%d%d",&q1,&q2);
        printf("%d\n",lca(q1,q2));
    }
    return 0;
}
