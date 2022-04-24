
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using uint=unsigned int;
const int maxn=5e6+10;
int n,q,p,m;
uint SA,SB,SC;
uint st[maxn];
int top;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int T=0;
    while(t--){ 
        cin>>n>>p>>q>>m>>SA>>SB>>SC;
        ll ans=0;
        top=0;
        for(int i=1;i<=n;++i){ 
            if((rng61()%(p+q)<p)){ 
                uint x=rng61()%m+1;
                st[++top]=x;
                st[top]=max(st[top],st[top-1]);
            }else
                top=max(top-1,0);
                ans=ans^((ll)i*st[top]);
        }
        cout<<"Case #"<<++T<<": "<<ans<<"\n";
    }
    return 0;
}
