#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2010;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]<0)a[i]=-a[i];
    }
    for(int i=1;i<=n;++i){
        int l=0,r=0;
        for(int j=1;j<=i-1;++j)
            if(a[j]<a[i])l++;
        for(int j=i+1;j<=n;++j)
            if(a[j]<a[i])r++;
        ans+=min(l,r);
    }
    cout<<ans<<"\n";
    
    return 0;
}