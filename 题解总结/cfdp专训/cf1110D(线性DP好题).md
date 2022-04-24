# cf1110D(线性DP好题)

题意：

给n张牌，要么$(i,i,i)$打出，要么三连环打出，问最多能打出的牌

思路：

首先很显然假如三连环数量超过2个，我们必定可以直接转为3个$(i,i,i)$的形式而不会更劣，所以三连环可以看作是用来补偿的

一开始用$dp[i]$表示前$i$种数所能打出的最大牌数，然后直接通过$dp[i-3]$转移，但是后来发现，这样的状态具备后效性，即之前的策略影响当前的选择。除此之外，我们发现$dp$计数中，未来的贡献未知但对当前决策有影响，这时候我们可以通过提前增加维度记录未来贡献的办法使得$dp$合理，显然$i$的贡献只有三种$(i,i,i),(i-2,i-1,i),(i-1,i,i+1),(i,i+1,i+2)$

最后两种是未来的贡献，我们增加维度记录即可

$dp[i][j][k]$表示前$i$种数做完，$j$个$(i-1,i,i+1)$，$k$个$(i,i+1,i+2)$，枚举上一阶段的某个维度转移即可

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int cnt[maxn],dp[maxn][3][3],n,m,mx=0,mn=maxn;
int main(){
    scanf("%d%d",&n,&m);
    int a;
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        cnt[a]++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=m;++i){
        for(int j=0;j<=2;++j){
            for(int k=0;k<=2;++k){
                for(int l=0;l<=2;++l){
                    if(cnt[i]<j+k+l||dp[i-1][k][l]==-1)continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+(cnt[i]-j-k-l)/3+j);
                }
            }
        }
    }
    cout<<dp[m][0][0];
    return 0;
}
```

启示：

$dp$计数中，未来的贡献未知但对当前决策有影响，这时候我们可以通过提前增加维度记录未来贡献的办法使得$dp$合理