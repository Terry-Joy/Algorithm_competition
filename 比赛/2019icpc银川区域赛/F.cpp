#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=998244353;
ll mypow(ll a,ll b)
{
   ll ans=1;
   while(b)
   { 
       if(b&1)ans=ans*a%mod;
       a=a*a%mod;
       b>>=1;
   }
   return ans;
}
ll inv(ll i)
{
   return mypow(i,mod-2); 
}
ll sum2(ll i){ 
    return  (((i%mod)*((i+1)%mod))%mod*(((2*i)%mod+1)%mod))%mod*inv(6)%mod; 
}
int main()
{
    ll n;
    scanf("%lld",&n);
    ll ans=0;
    ll k=sqrt(n)+1;
    for(ll i=2;i<=n;++i)
    { 
        ll res=1;
        if(i*i>n){ break;}
        else
        { 
            for(ll j=i,tmp=0;j<=n;j=res,tmp++)
            {
                res*=i;
                if(res>n)
                {
                    ans=ans+i%mod*tmp*(n%mod-j+1+mod)%mod%mod;
                    break; 
                }
                else ans=ans+i%mod*tmp*(res%mod-j+mod)%mod;
             }
        }
    }
    ans=(ans+(((((n+1)%mod*((n-k+1)%mod)%mod)%mod*(((n+k)%mod)*inv(2)%mod)%mod)%mod)+sum2(k-1)-sum2(n)+mod)%mod)%mod;    
    printf("%lld\n",ans);
    return 0;
}
