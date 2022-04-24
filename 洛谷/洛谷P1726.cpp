#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int N=5e3+10,M=1e5+10;
int head[N],ver[M],next1[M],dfn[N],low[N],tot,cnt,c[N],stack[N],top,num,vis[N],ans=-1,sum;
vector<int>scc[N];

void tarjan(int x)
{
    low[x]=dfn[x]=++num; 
    vis[x]=1;stack[++top]=x;
    for(int i=head[x];i;i=next1[i])
    {
        int y=ver[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]); 
        }
        else if(vis[y])
            low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;int z;
        int t=0;
        do{
            t++;
            z=stack[top--];c[z]=cnt;
            scc[cnt].push_back(z);vis[z]=0;
        }while(z!=x); 
        if(ans<=t)
        {
            ans=t;
            sum=cnt; 
        }
    }
}

void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

int main()
{ 
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        if(t==1)
        {
            add(a,b); 
        } 
        else 
        {
            add(a,b);
            add(b,a); 
        }
    }    

    for(int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;++i)
        if(c[i]==sum)
        {
            cout<<scc[sum].size()<<"\n";
            for(int j=i;j<=n;++j)
            {
               if(c[j]==sum) 
                   cout<<j<<" ";
            }
            return 0;
        }
    return 0;
}
