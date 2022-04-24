#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
int t,n,k;
ll p[105],ans=0;
bool ok(ll x,ll y){ 
    return !(100*x<=y*k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;++i)cin>>p[i];
        ll now=p[1];
        for(int i=2;i<=n;++i){ 
            if(ok(p[i],now)){ 
                ll x=p[i]*100;
                if(x%k==0)x/=k;
                else x=x/k+1;
                ans+=x-now;
                now=x;
            }
            now+=p[i];
        }
    cout<<ans<<"\n";
    }
    return 0;
}
