#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
typedef long long ll;
int dp[maxn][maxn][2][4],n,t,mod=998244353;
char a[maxn],b[maxn];
void add(int&x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(a+1)>>(b+1);
    int len1=strlen(a+1),len2=strlen(b+1);
    for(int i=0;i<=len1;++i){
        for(int j=0;j<=len2;++j){
            if(i<len1)add(dp[i+1][j][0][1],1);
            if(j<len2)add(dp[i][j+1][1][2],1);
            for(int st=0;st<4;++st){
                if(a[i+1]!=a[i]&&i<len1) add(dp[i+1][j][0][st|1],dp[i][j][0][st]);
                if(a[i]!=b[j+1]&&j<len2) add(dp[i][j+1][1][st|2],dp[i][j][0][st]);
                if(b[j]!=a[i+1]&&i<len1)   add(dp[i+1][j][0][st|1],dp[i][j][1][st]);
                if(b[j+1]!=b[j]&&j<len2)    add(dp[i][j+1][1][st|2],dp[i][j][1][st]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j)
            add(ans,dp[i][j][0][3]),add(ans,dp[i][j][1][3]);
    }
    cout<<ans<<"\n";
    return 0;
}