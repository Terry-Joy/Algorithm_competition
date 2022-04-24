#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
unordered_map<ll,ll>Map;
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
ll BSGS(ll A,ll B,bool f){ 
    Map.clear();
    ll m=floor(sqrt(p)+1),tmp=0;
    if(A%p==0&&B==0)return 1;
    if(A%p==0&&B!=0)return -1;
    for(int i=0;i<=m;++i){ 
        if(!i){ tmp=B%p;Map[tmp]=i;continue;}
        tmp=tmp*A%p;
        Map[tmp]=i;
    }
    tmp=1;ll t=mypow(A,m);
    for(int i=1;i*i<=p;++i){ 
        tmp=tmp*t%p;
        if(Map.find(tmp)!=Map.end()){ 
            ll ans=i*m-Map[tmp];
            if(f==0&&((ans&1)==0))
                return ans;
            else if(f==1&&((ans&1)==1))
                return ans;
        }
    }
    return -1;
}
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        Map.clear();
        ll n,x;
        scanf("%lld%lld",&n,&x);
        if(x==1){ 
            cout<<0<<"\n";
            continue;
        }
        if(!x){ 
           cout<<1<<"\n";
            continue;
        }
        ll x1=BSGS(n-1,(n*x%p+(n-1)+p)%p,1),x2=BSGS(n-1,((n*x)%p-(n-1)+p)%p,0);
        ll mn=1e18;
        if(x1==-1&&x2==-1)cout<<-1<<"\n";
        else{ 
            if(x1!=-1)mn=min(1ll*mn,x1);
            if(x2!=-1)mn=min(1ll*mn,x2);
            cout<<mn<<"\n";
        }
    }
    return 0;
}
