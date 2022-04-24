#include<bits/stdc++.h>
using namespace  std;
typedef long long ll;
unordered_map<int,ll>mp;
const int maxn=1e5+5;
int n,a[maxn],mo,q;
ll phi(int x){ 
    if(mp[x])return mp[x];
    int ans=x;int tmp=x;
    for(int i=2;i*i<=x;++i){ 
        if(x%i==0){ 
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ans=ans/x*(x-1);
    return mp[tmp]=ans;
}
ll Mod(ll x,ll m){ //拓展欧拉定理
    return x>=m?(x%m+m):x;
}
ll mypow(ll a,ll b,ll p){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=Mod(ans*a,p);
        a=Mod(a*a,p);
        b>>=1;
    }
    return ans;
}
ll solve(int l,int r,ll m){ 
    if(l==r||m==1)return Mod(a[l],m);
    return mypow(a[l],solve(l+1,r,phi(m)),m);
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>mo;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;++i){ 
        int l,r;
        cin>>l>>r;
        cout<<solve(l,r,mo)%mo<<"\n";//记得最后取模
    }
    return 0;
}
