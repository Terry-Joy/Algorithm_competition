#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

const int INF=0x7FFFFFFF;
const int maxn=1e5+10;
vector<int>v[maxn];             //存储第i个答案的原始答案位置
struct Node
{
   int val,no;
   bool operator<(const Node&a)const
   {
      return val<a.val; 
   } 
}node[maxn];

int n,m,q,c[maxn],x[maxn],y[maxn],t[maxn],que[maxn],ans[maxn];

void add(int x,int y)
{
   for(;x<=q;x+=x&-x)c[x]+=y; 
}

int ask(int x)
{
   int ans=0;
   for(;x;x-=x&-x)ans+=c[x];
   return ans; 
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&t[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
       scanf("%d%d",&x[i],&y[i]);
       v[y[i]].push_back(i); 
    }
    scanf("%d",&q);
    x[m+1]=INF;                 //边界处理！！！
    for(int i=1;i<=q;++i)
    {
       scanf("%d",&node[i].val);
       node[i].no=i; 
    }
    sort(node+1,node+1+q);
    for(int i=1;i<=q;++i)
        que[i]=node[i].val;
    int u,l,r,ls,rs;
    for(int i=1;i<=n;++i)
    {
       int J=v[i].size();
       for(int j=0;j<J;++j)
       {
          u=v[i][j];
          l=t[i]+1-x[u+1];      //计算每个答案偏移区间
          r=t[i]-x[u];
          ls=lower_bound(que+1,que+1+q,l)-que;      //二分贡献
          rs=upper_bound(que+1,que+1+q,r)-que-1;
          if(ls<=rs)
          {
             add(ls,1);                 //区间修改差分计算前缀和
             add(rs+1,-1); 
          } 
       }
    }
    for(int i=1;i<=q;++i)
        ans[node[i].no]=ask(i);
    for(int i=1;i<=q;++i)
        printf("%d ",ans[i]);
    return 0;
}
