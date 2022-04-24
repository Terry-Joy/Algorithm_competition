#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int c[maxn],a[maxn],t,b[maxn],m,n;
ll ask(int x){
    ll ans=0;
    while(x){
        ans+=c[x];
        x-=x&-x;
    }      
    return ans;
}
void add(int x){
    while(x<=m){
        c[x]+=1;
        x+=x&-x;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n&&n){ 
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;++i){ 
            cin>>a[i];
            a[i]++;b[i]=a[i];
        }
        sort(b+1,b+1+n);
        m=unique(b+1,b+1+n)-(b+1);
        for(int i=1;i<=n;++i)
            a[i]=lower_bound(b+1,b+1+m,a[i])-b;
        ll ans=0;
        for(int i=n;i>=1;--i){
            ans+=ask(a[i]-1);
            add(a[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
