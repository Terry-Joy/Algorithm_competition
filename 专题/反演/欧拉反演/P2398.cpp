#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
bool v[maxn];
int prime[maxn],phi[maxn],cnt;
void init(){
    v[1]=1;phi[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=2;i<maxn;++i)
        phi[i]+=phi[i-1];
}
int main(){
    init();
    int n;
    scanf("%d",&n);
    ll ans=0;
    for(int l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans+=1ll*(phi[r]-phi[l-1])*(n/l)*(n/l);
    }
    cout<<ans<<endl;
    return 0;
}