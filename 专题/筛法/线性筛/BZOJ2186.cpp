#include<bits/stdc++.h>

using namespace std;
int t,r,n,m;
const int maxn=1e7+5;
int fac[maxn],inv[maxn],ans[maxn],prime[maxn],cnt;
bool v[maxn];
void init(){
    fac[0]=fac[1]=1;inv[0]=inv[1]=1;
    ans[0]=ans[1]=1;
    for(int i=2;i<maxn;++i){
        fac[i]=1ll*fac[i-1]*i%r;
        inv[i]=1ll*(r-r/i)*inv[r%i]%r;
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=2;i<maxn;++i){
        ans[i]=ans[i-1];
        if(!v[i])ans[i]=1ll*ans[i]%r*(i-1)%r*inv[i]%r;
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t>>r;
    init();
    while(t--){
        cin>>n>>m;
        cout<<1ll*fac[n]%r*ans[m]%r<<"\n";
    }
    return 0;
}