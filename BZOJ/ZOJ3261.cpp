#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
const int Max=1e4+10;
const int Hash=1e9+7;   //用Hash映射避免边的重复
pair<int,int>edge[20010];//先存下所有的边，然后后面再去掉要毁灭的.
struct que
{
   char s[10];
   int a,b; 
}ask[50010];
int ans[50010],fa[Max],power[Max],n,m,q;
map<int,bool>beDes;     //要毁灭的边的坐标
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
void init(int n)
{
   for(int i=0;i<=n;++i)
      fa[i]=i; 
}
void merge(int x,int y)
{
   int fx=find(x);
   int fy=find(y);
   if(power[fx]>power[fy])
      fa[fy]=fx;
   else if(power[fy]>power[fx])
      fa[fx]=fy;
   else if(fx<fy)
      fa[fy]=fx;
   else if(fy<fx)
      fa[fx]=fy; 
}
int main()
{
    bool flag=false;
    while(~scanf("%d",&n))
    {
        init(n);
        for(int i=0;i<n;++i)
            scanf("%d",&power[i]);
        scanf("%d",&m);
        int a,b;
        for(int i=0;i<m;++i)
        {
           scanf("%d%d",&a,&b);
           if(a>b)
              swap(a,b);
           edge[i].first=a;
           edge[i].second=b; 
        }
        scanf("%d",&q);
        beDes.clear();
        for(int i=0;i<q;++i)
        {
           scanf("%s",ask[i].s);
           if(ask[i].s[0]=='q')
               scanf("%d",&ask[i].a);
           else
           {
              scanf("%d%d",&a,&b);
              if(a>b)
                 swap(a,b);
              ask[i].a=a;
              ask[i].b=b;
              beDes[a*Hash+b]=true; 
           }
        }
        for(int i=0;i<m;++i)
        {
           if(!beDes[edge[i].first*Hash+edge[i].second])
              merge(edge[i].first,edge[i].second); 
        }
        int num=0;
        for(int i=q-1;i>=0;--i)
        {
            a=ask[i].a;
            b=ask[i].b;
            int root=find(a);
            if(ask[i].s[0]=='q')
            {
               if(power[root]>power[a])
                  ans[++num]=root;
               else
                  ans[++num]=-1; 
            }
            else
            {
               merge(a,b); 
            }
        }
        if(flag)
            puts("");
        else
            flag=1;
        for(int i=num;i>0;--i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
