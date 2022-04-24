#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int h,t,ans[maxn],q[maxn],a[maxn],n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    h=1,t=0;
    for(int i=1;i<=n;++i){
        while(h<=t&&a[q[t]]<a[i]){
            ans[q[t]]=i;
            t--;
        }
        q[++t]=i;
    }
    for(int i=1;i<=n;++i)
        if(!ans[i])ans[i]=n+1;
    for(int i=1;i<=n;++i)
        cout<<min(a[i],ans[i]-i-1)<<" ";
    return 0;
}