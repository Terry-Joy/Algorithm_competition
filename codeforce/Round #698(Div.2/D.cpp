#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+5;
int t,n;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
ll a[maxn],k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        for(int i=1;i<=n;++i)cin>>a[i];
        ll G=a[2]-a[1];
        for(int i=3;i<=n;++i)
            G=gcd(G,a[i]-a[i-1]);
        bool flag=0;
        for(int i=1;i<=n;++i){ 
            if((k-a[i])%G==0){ 
                flag=1;break;
            }
        }
        cout<<(flag?"YES":"NO")<<"\n";
    }
    return 0;
}
