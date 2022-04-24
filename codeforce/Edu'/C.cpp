#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;
const int maxn=5e5+10;
int fa[maxn],size[maxn];
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
   x=find(x);
   y=find(y);
   if(x==y)return;
   if(size[x]<size[y])
      swap(x,y);
   fa[y]=x;
   size[x]+=size[y]; 
}
int main()
{ 
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
       fa[i]=i;
       size[i]=1; 
    }
    int k,a,b;
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&k);
        if(!k)continue;
        scanf("%d",&a);
        for(int i=1;i<k;++i)
        {
           scanf("%d",&b);
           merge(a,b); 
        }
    }
    for(int i=1;i<=n;++i)
        printf("%d ",size[find(i)]);
    return 0;
}
