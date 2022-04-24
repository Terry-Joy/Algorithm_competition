#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=2e4+10,M=2e5+10;
int head[N],ver[M],edge[M],next1[M],tot,v[N];
int n,m,l,r=-1,mid,a,b,c;
void add(int x,int y,int z)
{ 
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
bool dfs(int x,int clo,int mid)
{
    v[x]=clo;
    for(int i=head[x];i;i=next1[i])
    {
       int y=ver[i],z=edge[i];
       if(z>=mid)
       { 
         if(!v[y])dfs(y,3-clo,mid);
         else if(v[y]==clo)
            return false; 
       }
       else continue;
    }    
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    l=0,r=-1;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        r=max(r,c);
        add(a,b,c);
        add(b,a,c);
    }
    r=r+1;
    while(l+1<r)
    {
       int mid=l+r>>1;
       for(int i=1;i<=n;++i)
           v[i]=0;
       bool flag=1;
       for(int i=1;i<=n;++i)
           if(!v[i])
           { 
               if(!dfs(i,1,mid))
               {
                    flag=0;
                    break;
               }       
           }
       if(!flag)
           l=mid;
       else
           r=mid;
    }
    printf("%d\n",l);
    return 0;
}
