#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
unordered_map<ll,ll>mp;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,a;
    cin>>n;
    ll ans=0,sum=0;
    for(int i=1;i<=n;++i){ 
        cin>>a;
        sum+=a;
        if(mp[sum]||sum==0){ 
            ans++;
            mp.clear();
            sum=a;
            mp[sum]=i;
        }else{ 
            mp[sum]=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
