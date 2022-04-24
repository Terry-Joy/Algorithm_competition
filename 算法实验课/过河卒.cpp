#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=25;
ll dp[maxn][maxn];
int n,m,x,y;
bool is(int a,int b){
	return a>=0&&b>=0;
}
int main(){
	cin>>n>>m>>x>>y;
	dp[x][y]=-1;
	if(is(x-1,y-2))dp[x-1][y-2]=-1;
	if(is(x-2,y-1))dp[x-2][y-1]=-1;
	if(is(x-2,y+1))dp[x-2][y+1]=-1;
	if(is(x-1,y+2))dp[x-1][y+2]=-1;
	if(is(x+1,y+2))dp[x+1][y+2]=-1;
	if(is(x+2,y+1))dp[x+2][y+1]=-1;
	if(is(x+2,y-1))dp[x+2][y-1]=-1;
	if(is(x+1,y-2))dp[x+1][y-2]=-1;
	for(int i=0;i<=n;++i){
		if(dp[i][0]==-1)break;
		dp[i][0]=1;
	}
	for(int j=0;j<=m;++j){
		if(dp[0][j]==-1)break;
		dp[0][j]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(dp[i][j]==-1)continue;
			if(dp[i-1][j]!=-1)
				dp[i][j]+=dp[i-1][j];
			if(dp[i][j-1]!=-1)
				dp[i][j]+=dp[i][j-1];
		}
	}
	cout<<dp[n][m];
	return 0;
}