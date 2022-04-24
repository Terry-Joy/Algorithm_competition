#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+5;
bool is(int x,int y,int z){ 
    return (x<=y&&y<=z)||(x>=y&&y>=z);
}
int a[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i){ 
            cin>>a[i];
        }
        ll ans=n+n-1;
        for(int i=1;i+2<=n;++i){ 
            if(!is(a[i],a[i+1],a[i+2])){ 
                ans++;
                if((i+3)<=n&&!is(a[i],a[i+1],a[i+3])&&!is(a[i+1],a[i+2],a[i+3])&&!is(a[i],a[i+2],a[i+3]))
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
