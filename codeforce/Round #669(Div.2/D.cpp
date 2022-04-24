#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
const int INF=0x3f3f3f3f;
int a[maxn],cnt=1,dp[maxn],st1[maxn],st2[maxn],t1,t2;
int main(){ 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[1]=0;
    st1[++t1]=1;
    st2[++t2]=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1]+1;
        while(t1>0&&a[i]<=a[st1[t1]]){//递增
            int x=a[st1[t1--]];
            if(a[i]<x&&t1>0){
                dp[i]=min(dp[i],dp[st1[t1]]+1);
            }
        }
        st1[++t1]=i;
        while(t2>0&&a[i]>=a[st2[t2]]){//递减
            int x=a[st2[t2--]];
            if(a[i]>x&&t2>0){
                dp[i]=min(dp[i],dp[st2[t2]]+1);
            }
        }
        st2[++t2]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}
