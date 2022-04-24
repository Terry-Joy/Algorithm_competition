#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
int prime[maxn],cnt;
ll sum[maxn];
bool v[maxn];
void init(){ 
    for(int i=2;i<maxn;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=2;i<=cnt;++i)sum[i]=prime[i]+sum[i-1];
}
int main(){ 
    int t;
    scanf("%d",&t);
    init();
    int n;
    while(t--){ 
        scanf("%d",&n);
        int pos=upper_bound(prime+1,prime+1+cnt,n)-prime-1;
        ll ans=1ll*(3+n)*(n-2)/2+sum[pos];
        cout<<ans<<"\n";
    }
    return 0;
}
