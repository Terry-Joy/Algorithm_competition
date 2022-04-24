#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+10;
int fa[N];
bool flag[N];
int find(int x)
{
    if(x==fa[x])
        return x;
    return fa[x]=find(fa[x]); 
}
void init()
{
    for(int i=1;i<=N;++i)
    {
        fa[i]=i;
        flag[i]=0; 
    }
}
void Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)return;
    fa[y]=x; 
}
bool singleRoot(int n)
{
    int i=1;
    while(i<=n&&!flag[i])
        ++i;
    int root=find(i);
    while(i<=n)
    {
        if(flag[i]&&find(i)!=root)          //假如入度不为0但是根节点不是唯一的
        {
            return 0;
        }
        ++i; 
    }
    return 1;
}
int main()
{
    int x,y;
    bool is=1;
    int range=0;
    int idx=1;
    init();
    int t=1;
    while(~scanf("%d%d",&x,&y)&&(x!=-1&&y!=-1))
    {
        if(!x&&!y)
        {
            if(is&&singleRoot(range))           
                printf("Case %d is a tree.\n",t++);
            else
                printf("Case %d is not a tree.\n",t++);
            is=1;
            range=0;
            init();
            continue;
        } 
        if(!is)continue;             //假如已经不满足就一直跑到0 0
        range=max(range,x);
        range=max(range,y);
        flag[x]=flag[y]=1;              
        if(find(x)==find(y))        //如果在同一集合中又加边的话，说明成环或入度不唯一
            is=0;
        Union(x,y);
    }
    return 0;
}
