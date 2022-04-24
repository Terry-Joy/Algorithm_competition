#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>P;
map<P,int>mp;
int main(){
    int n;
    cin>>n;
    while(n--){
        int cnt2=0,cnt5=0;
        ld x;
        cin>>x;
        ll t=ll(x*1000000000.0);
        while(t%2==0)t/=2,cnt2++;
        while(t%5==0)t/=5,cnt5++;
        mp[make_pair(cnt2,cnt5)]++;
    }
    ll ans=1;
    for(auto&v:mp){
        for(auto&u:mp){
            if(v.first.first+u.first.first>=18&&v.first.second+u.first.second>=18){
                if(v==u){
                    ans+=1ll*v.second*(v.second-1);
                }
                else ans+=1ll*v.second*u.second;
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;
}