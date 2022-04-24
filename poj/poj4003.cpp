#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e4+10,M=1e5+10;
int head[N],max_len,s,next1[M],ver[M],edge[M],d[N],n,m,qmax[N],qmin[N],h1,t1,h2,t2,now,tot;
void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa,int len)
{
    if(max_len<=len)
    {
        max_len=len;
        s=now; 
    } 
    for(int i=head[now];i;i=next1[i])
    {
        if(ver[i]!=fa)
        {
            dfs(ver[i],now,len+edge[i]);
            d[ver[i]]=max(d[ver[i]],len+edge[i]); 
        } 
    }
}
int main()
{ 
    while(~scanf("%d%d",&n,&m)&&(n|m))
    {
        tot=0;
        for(int i=0;i<=n;++i)
            head[i]=0,d[i]=0;
        for(int i=1;i<n;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
                add(b,a,c);
        }
        max_len=0,s=0;
        dfs(1,0,0);
        dfs(s,0,0);
        dfs(s,0,0);
        for(int j=1;j<=m;++j)
        { 
            int k;
            scanf("%d",&k);
            t1=t2=0,h1=h2=1,now=0;
            int ans=0;
            for(int i=1;i<=n;++i)
            {
                while(h1<=t1&&d[i]>=d[qmax[t1]])
                    t1--;
                while(h2<=t2&&d[i]<=d[qmin[t2]])
                    t2--;
                qmax[++t1]=qmin[++t2]=i;
                while(d[qmax[h1]]-d[qmin[h2]]>k)
                {
                   if(qmax[h1]<qmin[h2])
                      now=qmax[h1++];
                   else
                      now=qmin[h2++]; 
                }
                ans=max(ans,i-now);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
