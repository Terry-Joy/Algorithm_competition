#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    int to, len;
};
#define INF 0x3f3f3f3f
const int N = 12;
int dp[1<<(N-1)][N];
int a[55][55];
int dis[N][N];
int main(){
    int n, m;
    while(cin>>n>>m){
        int x[11], y[11];
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
                if(a[i][j] || i==0&&j==0){
                    x[cnt] = i;
                    y[cnt++] = j;
                }
            }
        for(int i = 0; i < cnt; i++) // 建图
            for(int j = i+1; j < cnt; j++){
                int len = abs(x[i]-x[j])+abs(y[i]-y[j]);
                dis[i][j] = dis[j][i] = len;
            }
        memset(dp, INF, sizeof(dp));
        dp[1][0] = 0;
        for(int i = 1; i < (1<<cnt); i++){
            for(int j = 0; j < cnt; j++){  // j -> k
                if(!((1<<j) & i) ) continue;  // 未走过j 或 此路不通
                for(int k = 0; k < cnt; k++){
                    if(((1<<k)&i) ) continue;// 已走过k 或者 j k不通
                    dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j]+dis[j][k]);
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < cnt; i++) ans = min(ans, dp[(1<<cnt)-1][i] + dis[i][0]);
        cout<<ans<<endl;
    }
    return 0;
}