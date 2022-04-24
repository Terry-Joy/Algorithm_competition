#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using P=pair<int,int>;
using ll=long long;
const int maxn=1e5+10;
vector<P>res;
int hp[maxn],at[maxn];
int solve(int x){ 
    int l=1,r=x;
    while(l<r){ 
        int mid=l+r>>1;
        if((ll)mid*(mid+1)>=2*x)r=mid;
        else l=mid+1;
    }
    return r;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,T=0;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>hp[i]>>at[i];
        res.clear();
        for(int i=1;i<=n;++i){ 
            res.eb(make_pair(solve(hp[i]),at[i]));
        }
        sort(res.begin(),res.end(),[&](P a,P b){ 
                return (ll)a.se*b.fi>(ll)b.se*a.fi;
                });
        ll ans=0,num=0;
        for(auto u:res){ 
            num+=u.fi;
            ans+=num*u.se;
        }
        cout<<"Case #"<<++T<<": "<<ans<<"\n";
    }
    return 0;
}
