#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
int a[100],cnt;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ll p,q;
    cin>>t;
   while(t--){ 
       cnt=0;
      cin>>p>>q;
      if(p%q)cout<<p<<"\n";
      else{ 
        ll n=q;
        for(int i=2;i*i<=n;++i){ 
            if(n%i==0){ 
                a[++cnt]=i;
                while(n%i==0)n/=i;
            } 
        }
        if(n>1)a[++cnt]=n;
        ll ans=0;
        for(int i=1;i<=cnt;++i){ 
            ll x=p;
            while(x%q==0)x/=a[i];
            ans=max(ans,x);
        }
        cout<<ans<<"\n";
      }
   } 
    return 0;
}
