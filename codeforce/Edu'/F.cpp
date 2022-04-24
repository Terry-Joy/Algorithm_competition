#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
 
using namespace std;
const ll mod=1e9+7;
const int maxn=5e5+10;
map<int,int>mp;
ll c[maxn],sum[maxn];
int n,a[maxn],b[maxn];
void add(int x,int y)
{
   for(;x<=n;x+=x&-x)c[x]+=y; 
}
ll ask(int x)
{
   ll ans=0;
   for(;x;x-=x&-x)ans+=c[x];
   return ans;
}
int main()
{ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
       scanf("%d",&a[i]);
       b[i]=a[i]; 
    }
    sort(b+1,b+1+n);//离散化
    for(int i=1;i<=n;++i)
        mp[b[i]]=i;
    for(int i=1;i<=n;++i)
    {
       sum[i]=ask(mp[a[i]])*(n-i+1)%mod;    //前面比他小的
       add(mp[a[i]],i);     //左边区间个数 
    }
    for(int i=1;i<=n;++i)
        c[i]=0;
    for(int i=n;i>=1;--i)
    {
       sum[i]=(sum[i]+ask(mp[a[i]])*i%mod)%mod;   //右边比他小
       add(mp[a[i]],n-i+1);
       sum[i]=(sum[i]+(ll)(n-i+1)*i%mod)%mod;//还要统计自己d的
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
        ans=(ans+(ll)a[i]*sum[i]%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}