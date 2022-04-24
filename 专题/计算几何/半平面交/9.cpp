#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
typedef long long ll;
bool check(int x){
	 if(x==2||x==3)return 1;
	 if(x==1)return 0;
    if(x%2==0)return 0;
   
    for(int i=3;i<=sqrt(x);i+=2)
        if(x%i==0)return 0;
    return 1;
}
ll a[maxn],sum[maxn];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=1e18;
    ll ans=1e18;
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    for(ll i=a[(n+1)/2];i>1;--i){
        ll mn=0;
        if(check(i)){
            ll pos=upper_bound(a+1,a+1+n,i)-a;
            if(pos>=1)
                mn+=((pos-1)*i-sum[pos-1]);
            if(pos<=n)
                mn+=((sum[n]-sum[pos-1])-1ll*(n-pos+1)*i);
            ans=min(ans,mn);
            break;
        }
    }
    for(ll i=a[(n+1)/2];i<=1e18;++i){
        ll mn=0;
        if(check(i)){
            int pos=upper_bound(a+1,a+1+n,i)-a;
            if(pos>=1)
            mn+=(1ll*(pos-1)*i-sum[pos-1]);
            if(pos<=n)
                mn+=((sum[n]-sum[pos-1])-1ll*(n-pos+1)*i);
            ans=min(ans,mn);
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}