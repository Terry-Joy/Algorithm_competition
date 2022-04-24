#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 

using namespace std;
const int maxn=450;
double dp[maxn][maxn],ans;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)dp[0][i]=i;
    for(int i=1;i<=m;++i)
        for(int j=0;j<=n;++j)
        {
           if(j)dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])/2;
           if(j<n)dp[i][j]=max(dp[i][j],(dp[i-1][j]+dp[i-1][j+1])/2.0);
        }
    printf("%.10lf",dp[m][0]);
   return 0; 
}
