#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e7+3;
const int mod=1e9+7;
int prime[1270620],S1[maxn],S2[maxn],cnt,n,k;
bool v[maxn];
int mypow(ll a,int b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){
	S2[1]=S1[1]=1; 
    for(int i=2;i<=n;++i){
        if(!v[i])prime[++cnt]=i,S1[i]=1-mypow(i,2*k),S2[i]=mypow(i,k);
        for(int j=1;j<=cnt;++j){
            int x=i*prime[j];
            if(x>=maxn)break;
            v[x]=1;
            if(i%prime[j]==0){
                S1[x]=S1[i];
                ll w=(long long )S2[i]*S2[prime[j]];
                if(w>=mod)S2[x]=w%mod;
                else S2[x]=w;
                break;
            }
            S1[x]=(ll)S1[i]*S1[prime[j]]%mod;
            ll w=(ll)S2[i]*S2[prime[j]];
            if(w>=mod)S2[x]=w%mod;
            else S2[x]=w;
        }
    }
    for(int i=1;i<=n;++i){
        S1[i]+=S1[i-1];
        if(S1[i]>=mod)S1[i]-=mod;
        if(S1[i]<0)S1[i]+=mod;
        S2[i]+=S2[i-1];
        if(S2[i]>=mod)S2[i]-=mod;
    }
}
int main(){
    scanf("%d%d",&n,&k);
    init();
    int ans=0;
    for(int i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        ans=(ans+(ll)(S1[j]-S1[i-1]+mod)*S2[n/i]%mod*S2[n/i]%mod);
        if(ans>=mod)ans-=mod;
    }
    cout<<ans;
    return 0;
}