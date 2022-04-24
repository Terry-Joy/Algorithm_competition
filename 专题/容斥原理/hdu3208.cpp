
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[63];
const double eps=1e-18;
const ll inf = (ll)(1e18) + 500;
const ll INF = (ll)1 << 31;
 
ll mypow(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1){
            double judge=1.0*inf/ans;
            if(a>judge) return -1;
            ans*=a;
        }
        b>>=1;
        if(a>INF&&b>0) return -1;
        a=a*a;
    }
    return ans;
}
ll Find(ll n,ll k)//手动扩大pow精度
{
    ll a=1ll*pow(n,1.0/k);
    ll q1=mypow(a,k);
    ll q2=mypow(a-1,k);
    ll q3=mypow(a+1,k);
    if(q3!=-1&&q3<=n)return a+1;
    else if(q1!=-1&&q1<=n)return a;
    else if(q2!=-1&&q2<=n)return a-1;
}
 
ll solve(ll n){
    sum[1]=n;
    int maxx=0;
    for(int i=2;i<=62;i++)//枚举63位幂
    { 
        sum[i]=Find(n,1ll*i)-1;
        if(!sum[i]){
            maxx=i;//记录达到的最大的幂是多少
            break;
        }
    }
    for(int i=maxx;i>=2;i--)//从大到小枚举容斥
        for(int j=1;j<i;j++)
            if(i%j==0) sum[j]-=sum[i];
    ll res=0;
    for(int i=1;i<=maxx;i++)
        res+=sum[i]*i;
    return res;
}
int main()
{
    ll a,b;
    while(~scanf("%lld%lld",&a,&b)&&a)
        printf("%lld\n",solve(b)-solve(a-1));
    return 0;
}
