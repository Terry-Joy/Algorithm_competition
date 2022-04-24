#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
unordered_map<ll,bool>mp;
int t,n;
ll k;
int getLen(ll x){ 
    int cnt=0;
    while(x){ 
        cnt++;
        x/=10;
    }
    return cnt;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        mp.clear();
        cin>>n>>k;
        ll ans=k;
        mp[k]=1;
        while(1){ 
            ll now=k*k;
            int len=getLen(now);
            int w=len-n;
            now/=pow(10,len-n);
            if(mp[now])break;
            k=now;
            mp[now]=1;
            ans=max(ans,now);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
