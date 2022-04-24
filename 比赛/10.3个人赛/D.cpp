#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int>mp;
const int maxn=1010;
const int INF=0x3f3f3f3f;
int dp[maxn],a[1010],g[maxn][maxn];
int main(){
    int t,n,k,m;
    scanf("%d",&t);
    while(t--)
	{
        mp.clear();
        scanf("%d%d",&n,&k);
		for(int i=0;i<=n;++i)dp[i]=INF;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
                g[i][j]=0;
        int num=INF;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i){
            mp.clear();
            mp[a[i]]++;
            for(int j=i+1;j<=n;++j){
                mp[a[j]]++;
                if(mp[a[j]]==2)g[i][j]=g[i][j-1]+2;
                else if(mp[a[j]]>=3)g[i][j]=g[i][j-1]+1;
                else g[i][j]=g[i][j-1];
            }
        }
		dp[0]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=i;++j)
				dp[i]=min(dp[i],dp[j]+k+g[j+1][i]);	
		}
        printf("%d\n",dp[n]);
    }
    return 0;
}