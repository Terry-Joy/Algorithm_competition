#include<bits/stdc++.h>

using namespace std;
const int maxn=4e4+5;
int dp[maxn],v[105],w[105],m[105],h,t,q[maxn],n,V;
inline int getMax(int i,int j,int f){
    return dp[j+f*w[i]]-f*v[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>V;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i]>>m[i];
    dp[0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=w[i]-1;++j){
            h=1,t=0;
            int mxF=(V-j)/w[i];
            //初始化决策集合
            for(int k=mxF-1;k>=max(0,mxF-m[i]);--k){
                while(h<=t&&getMax(i,j,q[t])<=getMax(i,j,k))t--;
                q[++t]=k;
            }
            for(int k=mxF;k>=0;k--){
                while(h<=t&&q[h]>k-1)h++;
                if(h<=t)
                    dp[j+k*w[i]]=max(dp[j+k*w[i]],getMax(i,j,q[h])+k*v[i]);
                if(k-m[i]-1>=0){
                    while(h<=t&&getMax(i,j,q[t])<=getMax(i,j,k-m[i]-1))t--;
                    q[++t]=k-m[i]-1;
                }
            }
        }
    } 
    /*int ans=0;
    for(int i=1;i<=V;++i)ans=max(ans,dp[i]);
    cout<<ans;*/
    cout<<dp[V];
    return 0;
}