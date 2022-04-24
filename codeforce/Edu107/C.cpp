#include<bits/stdc++.h>
#define pb push_back 
#define fi first  
#define se second
using namespace std;
const int maxn=3e5+5;
int n,q,cnt[52],a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    int mx=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mx=max(mx,a[i]);
        if(!cnt[a[i]])cnt[a[i]]=i;
    }
    int x;
    for(int i=1;i<=q;++i){
        cin>>x;
        cout<<cnt[x]<<" ";
        for(int j=1;j<=mx;++j){
            if(cnt[j]<cnt[x])cnt[j]+=1;
        }
        cnt[x]=1;
    }
    return 0;
}