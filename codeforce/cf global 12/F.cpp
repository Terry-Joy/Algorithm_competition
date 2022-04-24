#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int a[maxn],cnt[maxn],sum[maxn],t,n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        k=0;
        for(int i=1;i<=n;++i)cnt[i]=sum[i]=0;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){
            if(a[i]==a[i-1]){
                k++;
                sum[a[i]]+=2;
            }
            cnt[a[i]]++;
        }
        sum[a[1]]++;sum[a[n]]++;
        int mxcnt=-1,mxsum=-1;
        for(int i=1;i<=n;++i){
            mxcnt=max(mxcnt,cnt[i]);
            mxsum=max(mxsum,sum[i]);
        }
        if(mxcnt>(n+1)/2){
            cout<<"-1"<<"\n";continue;
        }else{
            cout<<k+max(0,mxsum-(k+2))<<"\n";
        }
    }
    return 0;
}