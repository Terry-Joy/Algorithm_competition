#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[12],n,m,j,ans,cnt;
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b; }
void dfs(int pos,int sum,int li)
{
    sum=lcm(a[pos],sum);
    if(sum>m)return;
    if(li&1)
        ans+=(m/sum);
    else ans-=(m/sum);
    for(int i=pos+1;i<=n;++i)
        dfs(i,sum,li+1);
}
int main()
{
    int b;
    while(~scanf("%d%d",&n,&m)){ 
        ans=0;
        for(int i=1;i<=n;++i){ 
            scanf("%d",&a[i]);
        }
        for(int j=1;j<=n;++j)
            dfs(j,a[j],1);
        printf("%d\n",ans);
    } 
    return 0; 
}
