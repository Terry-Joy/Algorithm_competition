#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll sum[N],f[N],s[N];
int a[N];
int n;
int calc(int rr,ll lim){
    int ret=-1;
    for (int l=1,r=rr,mid=(l+r)>>1; l<=r; mid=(l+r)>>1)
    if (a[mid]<lim) ret=mid,r=mid-1; else l=mid+1;
    return ret;
}
int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for (int i=1; i<=n; ++i) s[i]=s[i-1]+a[i];
    for (int i=1; i<=n-4; ++i) sum[i]=s[i+4]-s[i];
    for (int i=n-4; i>=1; --i) f[i]=sum[i]-a[i];
    
    vector<pair<int,ll> > v;
    ll ans=-1;
    for (int p2=n-5; p2>=2; --p2){
        while (v.size()&&f[p2+1]>=v.back().second) v.pop_back();
        v.push_back(make_pair(p2+1,f[p2+1]));
        int ret=-1;
        for (int l=0,r=(int)v.size()-1,mid=(l+r)>>1; l<=r; mid=(l+r)>>1)
        if (a[p2]<v[mid].second) ret=mid,l=mid+1; else r=mid-1;
        if (ret==-1) continue;
        int p1=calc(p2-1,a[p2]+a[v[ret].first]);
        if (p1==-1) continue;
        ans=max(ans,a[p1]+a[p2]+a[v[ret].first]+sum[v[ret].first]);
    }
    cout<<ans;
}