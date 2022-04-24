#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll sum[maxn];
int n,q,t,a[maxn];
unordered_map<ll,bool>mp;
void work(int l,int r){ 
    if(r<l||l<1||r>n)return;
    if(a[l]==a[r]){ 
        mp[1ll*a[l]*(r-l+1)]=1;
        return;
    }
    ll ans=(a[l]+a[r])/2;
    ll mid=upper_bound(a+l,a+r+1,ans)-a-1;
    work(l,mid);
    work(mid+1,r);
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        mp.clear();
        cin>>n>>q;
        for(int i=1;i<=n;++i)cin>>a[i],sum[i]=0;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
        work(1,n);
        ll s;
        for(int i=1;i<=q;++i){ 
            cin>>s;
            if(!mp[s])cout<<"No\n";
            else cout<<"Yes\n";
        }
    }
    return 0;
}
