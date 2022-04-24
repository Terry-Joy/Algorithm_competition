#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e4+10;
int fa[N],n;
struct Node{ 
    int p,d;
    bool operator<(const Node&y)const
    {
       if(p!=y.p)return p>y.p;
       return d<y.d; 
    }
}k[N];
int find(int x)
{ 
    return (fa[x]==-1)?x:fa[x]=find(fa[x]);
}
int main()
{
    while(~scanf("%d",&n))
    { 
        for(int i=1;i<=n;++i)
            scanf("%d%d",&k[i].p,&k[i].d);
        sort(k+1,k+1+n);
        memset(fa,-1,sizeof(fa));
        int ans=0;
        for(int i=1;i<=n;++i){ 
            int j=find(k[i].d);
            if(j>0)
            {
                fa[j]=j-1;
                ans+=k[i].p;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
