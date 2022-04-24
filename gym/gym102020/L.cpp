#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
int dp[maxn][maxn];
int n,q,sum,k;
struct Node{ 
    int v,w,t;
    bool operator<(const Node&a)
    { 
        return t>a.t;    
    }
}res[maxn];
int find(int x)
{
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(res[mid].t<=x)
            r=mid-1;
        else
            l=mid;
    } 
    return l;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d",&res[i].v,&res[i].w,&res[i].t);
    sort(res+1,res+1+n);
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=10000;++j)
        {
            if(res[i].w>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-res[i].w]+res[i].v); 
        } 
    }
    for(int i=1;i<=q;++i)
    {
        scanf("%d%d",&sum,&k);
        printf("%d\n",dp[find(sum)][k]); 
    }
    return 0;
}
