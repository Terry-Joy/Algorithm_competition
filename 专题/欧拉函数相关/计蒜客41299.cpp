#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,ll>mp;
const int maxn=1e5+5;
int n,a,b,mo,q;
int phi(int x){ //记得记搜 实在被卡常才上线性筛优化
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
        if(b&1)ans=Mod(ans*a,p);//自定义取模
        a=Mod(a*a,p);
        b>>=1;
    }
    return ans;
}
ll solve(int l,ll m){ 
    if(l==1||m==1)return Mod(a,m);
    return mypow(a,solve(l-1,phi(m)),m);
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    for(int i=1;i<=q;++i){ 
        cin>>a>>b>>mo;
        if(a==1){ cout<<1%mo<<"\n";continue;}//这里也得模
        if(b==0){ cout<<1%mo<<"\n";continue;}//特判 记得取模
        cout<<solve(b,mo)%mo<<"\n";//记得最后取模
    }
    return 0;
}
