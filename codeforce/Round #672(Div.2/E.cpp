#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[85],pos[85],cnt;
int dp[82][82][82*82];
int main(){ 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){ 
        scanf("%d",&a[i]);
        if(a[i])pos[++cnt]=i;
    }
    int ans=0;
    int N=n*(n-1)/2;
    ans=n*(n-1)/2-cnt*(cnt-1)/2-cnt*(n-cnt);
    for(int i=0;i<=cnt;++i)
        for(int j=0;j<=n;++j)
            for(int k=0;k<=N;++k)dp[i][j][k]=0x3f3f3f3f;
    int sum=0;
    for(int i=0;i<=cnt;++i){
        if(i>=1) 
             sum+=max(0,(pos[i]-pos[i-1]-1)*(pos[i]-pos[i-1]-2)/2);
        dp[i][pos[i]][0]=sum;
    }
    for(int i=1;i<=cnt;++i)
        for(int j=1;j<=n;++j)
            for(int t=0;t<j;++t)
                for(int k=0;k<=N;++k){ 
                    if(dp[i-1][t][k]==0x3f3f3f3f)continue;
                    dp[i][j][k+abs(pos[i]-j)]=min(dp[i][j][k+abs(pos[i]-j)],dp[i-1][t][k]+max(0,(j-t-1)*(j-t-2)/2));
                }
    int mx=0x3f3f3f3f;
    for(int i=0;i<=N;++i){ 
        for(int j=1;j<=n;++j){ 
            if(dp[cnt][j][i]==0x3f3f3f3f)continue;
            mx=min(mx,dp[cnt][j][i]+max(0,(n-j-1)*(n-j)/2));
        }
        if(!cnt){printf("0 ");continue;}
        printf("%d ",ans-mx); 
    }
    return 0;
}
