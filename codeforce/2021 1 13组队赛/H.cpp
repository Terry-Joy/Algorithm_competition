#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int INF=0x3f3f3f3f; 
int dp[2][maxn][maxn][maxn],limit=0;//前i,j,当前k,l
char s1[maxn],s2[maxn],len1,len2;
int solve(){ 
    for(int i=0;i<=len2;++i)
        for(int j=0;j<=len1;++j)
            for(int k=0;k<=len2;++k)
                dp[0][i][j][k]=INF;
    dp[0][0][0][0]=0;
    for(int i=0;i<=len1;++i){ 
        for(int j=0;j<=len2;++j)
            for(int k=0;k<=len1;++k)
                for(int f=0;f<=len2;++f){ 
                    dp[(i+1)&1][j][k][f]=INF;
                }
        for(int j=0;j<=len2;++j){ 
            for(int k=len1;k>=0;--k)
                for(int f=len2;f>=0;--f){ 
                    if(dp[i&1][j][k][f]==INF)continue;
                    if(k>=limit&&f>=limit)dp[i&1][j][0][0]=min(dp[i&1][j][0][0],dp[i&1][j][k][f]);
                    if(k>=limit)dp[i&1][j][0][f]=min(dp[i&1][j][0][f],dp[i&1][j][k][f]);               //当前段是否匹配完成
                    if(f>=limit)dp[i&1][j][k][0]=min(dp[i&1][j][k][0],dp[i&1][j][k][f]);
                    
                    if(i!=len1&&!f)
                        dp[(i+1)&1][j][k+1][0]=min(dp[(i+1)&1][j][k+1][0],dp[i&1][j][k][f]+1);//s1匹配 s2等下个位置
                    if(j!=len2&&!k)
                        dp[i&1][j+1][0][f+1]=min(dp[i&1][j+1][0][f+1],dp[i&1][j][k][f]+1);//s1等下个位置
                    if(i!=len1&&j!=len2){ 
                        if(s1[i+1]==s2[j+1])
                            dp[(i+1)&1][j+1][k+1][f+1]=min(dp[(i+1)&1][j+1][k+1][f+1],dp[i&1][j][k][f]+1);//都匹配一步
                }
            }
        }
    }
    return dp[(len1)&1][len2][0][0];
}
int main(){ 
    scanf("%d%s%s",&limit,s1+1,s2+1);
    len1=strlen(s1+1),len2=strlen(s2+1);
    cout<<solve();
    return 0;

}
