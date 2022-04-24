#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
ll dp[105][maxn][2],mn[15][maxn],mx[15][maxn];
unordered_map<char,int>mp;
char s[maxn];
int t,len[105],cnt,num,x;
int s1[10]={0,0,1,7,4,5,9,8},s2[10]={0,0,1,7,4,2,0,8};
int main(){
    mp['1']=2;mp['7']=3;mp['4']=4;
    mp['5']=mp['2']=mp['3']=5;
    mp['0']=mp['6']=mp['9']=6;
    mp['8']=7;
    scanf("%d",&t);
    for(int i=1;i<=10;++i){
        for(int j=2;j<maxn;++j){
            g[i][j]=1e18;
            dp[i][j]=dp[i][j-1];
            for(int k=2;k<=7;++k)
                if(j-k>=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-k]*10+s1[k],dp[i][j]);
        }
    }
    for(int i=1;i<=10;++i){
        for(int j=2;j<maxn;++j){
            if(i==1){
                g[i][j]=1;continue;
            }
            g[i][j]=g[i][j-1];
            for(int k=2;k<=7;++k)
                if(j-k>=0)
                    g[i][j]=min(g[i][j],g[i-1][j-k]*10+s2[k],g[i][j]);
        }
    }
    while(t--){
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        scanf("%s",s+1);
        cnt=num=x=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='+'||s[i]=='-'){
                len[++num]=cnt;
                cnt=0;
                if(s[i]=='+')x+=2;
                else x+=1;
            }else{
                cnt++;
                x+=mp[s[i]];
            }
        }
        len[++num]=cnt;
        for(int i=2;i<=x;++i)dp[1][i][0]=dp[1][i][1]=mx[len[1]][i];
        for(int i=2;i<=num;++i){
            for(int j=2;j<=x;++j)
                for(int k=2;k<=j;++k){
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k-2][1]+f[len[i]][k]);
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k-2][0]+f[len[i]][k]);
                }
        }
    }
    return 0;
}