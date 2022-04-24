
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,k,n;
const int maxn=2e5+5;
ll a[maxn];
int main(){
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        for(int i=2;i<n;++i)
            a[i]+=a[i-1];
        int tmp=max(0,n-1-k);
        cout<<a[n]+a[n-1]-a[tmp]<<endl;
    }
    return 0;
}