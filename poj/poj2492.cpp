#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int fa[2010],road[2010],t;
int n,m;
int find(int x)
{
    if(x==fa[x])return x;
    else{ 
        int t=fa[x];
        fa[x]=find(fa[x]);
        road[x]=(road[x]+road[t])%2;
        return fa[x];
    } 
}
void init()
{
    for(int i=1;i<=n;++i)
        fa[i]=i, road[i]=0;
}
int main()
{
    scanf("%d",&t);
    int k=1;
    while(t--)
    {
        scanf("%d%d",&n,&m); 
        int flag=1;
        init();
        for(int i=1;i<=m;++i)
        { 
            int a,b;
            scanf("%d%d",&a,&b);
            int fx=find(a);
            int fy=find(b);
            if(fx!=fy)
            {
                fa[fy]=fx;
                road[fy]=(road[b]+road[a]+1)%2;
            }
            else 
            {
                if(road[a]==road[b])
                    flag=0;
            }
        }
        printf("Scenario #%d:\n",k++);
        if(!flag)
            puts("Suspicious bugs found!");
        else
            puts("No suspicious bugs found!");
         putchar('\n');
    }
    return 0;
}
