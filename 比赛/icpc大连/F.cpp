#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+5;
ll sum[maxn+10],mul[maxn+10];
void init(){ 
    sum[1]=0;
    mul[1]=1;
    for(int i=2;i<maxn;++i){ 
        sum[i]=sum[i-1]+i;
        mul[i]=(mul[i-1]*i)%mod;
    }
}
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    int t,x;
    init();
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&x);
        if(x<=4){ 
            cout<<x<<"\n";continue;
        }
        int id=upper_bound(sum+1,sum+1+maxn,x)-sum-1;
        int res=x-sum[id];
        ll ans;
        if(id==res)
            ans=mul[id]*((mod+1)/2)%mod*(id+2)%mod;
        else
            ans=mul[id+1]*mypow(id-res+1,mod-2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
