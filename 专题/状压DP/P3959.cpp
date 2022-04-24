#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=13;
const int maxs=1<<12;
const int inf=0x3f3f3f3f;

int n,m,ans,G[maxn][maxn];
int road[maxs][maxn],expand[maxs],f[maxn][maxs];
vector<int> valid[maxs],cost[maxs];

void init(){
	memset(road,0x3f,sizeof(road));
	for(int s=0;s<1<<n;s++){
		expand[s]=s;
		for(int i=1;i<=n;i++){
			if(s>>(i-1)&1){
				road[s][i]=0;
				for(int j=1;j<=n;j++){
					if(G[i][j]==inf)continue;
					expand[s]|=1<<(j-1);
					road[s][j]=min(road[s][j],G[i][j]);
				}
			}
		}
	}
	for(int s=0;s<1<<n;s++){
		for(int k=s;k;k=(k-1)&s){
			if((s&expand[k])==s){
				int sum=0;
				for(int i=1;i<=n;i++)
					if((s^k)>>(i-1)&1)sum+=road[k][i];
				valid[s].pb(k),cost[s].pb(sum);
			}
		}
	}
}

void solve(){
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[1][1<<(i-1)]=0;
	ans=f[1][(1<<n)-1];
	for(int i=2;i<=n;i++){
		for(int s=0;s<1<<n;s++){
			for(int p=0;p<valid[s].size();p++){
				int k=valid[s][p];
				f[i][s]=min(f[i][s],f[i-1][k]+(i-1)*cost[s][p]);
			}
		}
		ans=min(ans,f[i][(1<<n)-1]);
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d%d",&n,&m);
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		G[x][y]=G[y][x]=min(G[x][y],z);
	}	
	init();
	solve();
	return 0;
} 
