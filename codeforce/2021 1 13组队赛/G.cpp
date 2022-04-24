#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=55;
int ans[maxn]={ 0,2,1},num,n;
ll f;
bool check(ll mod){ 
    ll s=0;
    for(int i=num;i>=1;--i)
        s=(s*10+ans[i])%mod;
    if(!s)return 1;
    return 0;
}
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n;
    if(n==1){ cout<<"2";return 0;}
    else if(n==2){ cout<<"2112";return 0;}
    num=2;
    for(int i=3;i<=n;++i){ 
        f=1ll<<i;
        num++;
        for(int j=1;j<=2;++j){ 
            ans[num]=j;
            if(check(f))break;
        }
    }
    for(int i=num;i>=1;--i)cout<<ans[i];
    return 0;
}
