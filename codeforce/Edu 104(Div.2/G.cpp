#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int mod=998244353;
int t,n,c[27],dp[2][405][405][3][3],sum[405][405];
//最多2个超限制下前i个字母j个第一个k个第二个，倒数第二个和倒数第一个状态分别为0/1/2
void add(int&x,int y){
    x+=y; if(x>=mod)x-=mod;
}
void sub(int&x,int y){
    x-=y;if(x<0)x+=mod;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<26;++i)cin>>c[i];
    dp[0][0][0][0][0]=1;
    int now=0;
    for(int i=0;i<n;++i){
        now^=1;
        for(int j=0;j<=i;++j)
            for(int k=0;k+j<=i;++k)
                for(int f=0;f<3;++f)
                    for(int d=0;d<3;++d)
                        dp[now][j][k][f][d]=0;
        for(int j=0;j<=i;++j)
            for(int k=0;k+j<=i;++k){
                for(int f=0;f<3;++f)
                    for(int d=0;d<3;++d){
                        if(!dp[now^1][j][k][f][d])continue;//当前0
                            add(dp[now][j][k][d][0],1ll*dp[now^1][j][k][f][d]*(f==0&&i>=2?23:24)%mod);
                        if(f!=1)//当前1
                            add(dp[now][j+1][k][d][1],dp[now^1][j][k][f][d]);
                        if(f!=2)//当前2
                            add(dp[now][j][k+1][d][2],dp[now^1][j][k][f][d]);
                    }
            }
    }
    for(int j=0;j<=n;++j)
        for(int k=0;k+j<=n;++k)
            for(int f=0;f<3;++f)
                for(int d=0;d<3;++d)
                    add(sum[j][k],dp[now][j][k][f][d]);
    //二维后缀和
    for(int i=n;i>=0;--i)
        for(int j=n;j>=0;--j){
            add(sum[i][j],sum[i+1][j]);
            add(sum[i][j],sum[i][j+1]);
            sub(sum[i][j],sum[i+1][j+1]);
        }
    int ans=1;
    for(int i=0;i<n;++i){
        if(i<2)ans=1ll*ans*26%mod;
        else ans=1ll*ans*25%mod;
    }
    for(int i=0;i<26;++i){//容斥
        sub(ans,sum[c[i]+1][0]);
    }
    for(int i=0;i<26;++i)
        for(int j=i+1;j<26;++j)
            add(ans,sum[c[i]+1][c[j]+1]);
    cout<<ans<<"\n";
    return 0;
}
