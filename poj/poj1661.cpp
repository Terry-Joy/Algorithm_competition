#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1020;
struct Node{ 
    int l,r,h;
    bool operator<(const Node&a)const
    {
       return h<a.h; 
    }
}node[maxn];
int dp[maxn][2];
int main()
{
    int t,n,l,r,maxh;
    scanf("%d",&t);
    while(t--)
    { 
       memset(dp,0x3f,sizeof(dp));
       scanf("%d%d%d%d",&n,&l,&r,&maxh);
       for(int i=0;i<n;++i) 
            scanf("%d%d%d",&node[i].l,&node[i].r,&node[i].h);
       node[n].l=l,node[n].r=l,node[n].h=r;
       sort(node,node+n);
       int lp,rp;
       for(int j=0;j<=n;++j)
       {
          lp=rp=-1;
          for(int k=j-1;k>=0;--k)
          {
             if(lp==-1&&node[k].l<=node[j].l&&node[k].r>=node[j].l)
                lp=k;
             if(rp==-1&&node[k].l<=node[j].r&&node[k].r>=node[j].r)
                rp=k; 
          } 
          if(lp==-1&&node[j].h<=maxh)//左下方没有但能落地时
              dp[j][0]=node[j].h;
          if(rp==-1&&node[j].h<=maxh)//右下方没有但能落地时
              dp[j][1]=node[j].h;
          if(lp!=-1&&node[j].h-node[lp].h<=maxh)
              dp[j][0]=min(dp[lp][0]+node[j].l-node[lp].l,dp[lp][1]+node[lp].r-node[j].l)+node[j].h-node[lp].h;
          if(rp!=-1&&node[j].h-node[rp].h<=maxh)
              dp[j][1]=min(dp[rp][1]+node[rp].r-node[j].r,dp[rp][0]+node[j].r-node[rp].l)+node[j].h-node[rp].h;
       }
       printf("%d\n",dp[n][0]);
    }
    return 0;
}
