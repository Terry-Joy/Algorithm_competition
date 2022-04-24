#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+5;
struct Node{ 
    ll data;
    int id;
}r[maxn],c[maxn][maxn];
int rh,rt,ch[maxn],ct[maxn];
int n,m,k,u;
ll dp[maxn][maxn];
int a[maxn][maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m>>k>>u){ 
        for(int i=1;i<=m;++i){ ch[i]=1;ct[i]=0;}
        rh=1;rt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){ 
                cin>>a[i][j];
            }
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j)
                dp[i][j]=-1;
        dp[1][1]=a[1][1];
        for(int i=1;i<=n;++i){ 
            rh=1;rt=0;
            for(int j=1;j<=m;++j){ 
                while(ch[j]<=ct[j]&&i-c[j][ch[j]].id>k)ch[j]++;
                while(rh<=rt&&j-r[rh].id>k)rh++;
                if(a[i][j]>0){ 
                    if(dp[i-1][j]!=-1)dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j]);
                    if(dp[i][j-1]!=-1)dp[i][j]=max(dp[i][j-1]+a[i][j],dp[i][j]);
                    if(dp[i-1][j-1]!=-1)dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i][j]);
                    if(ch[j]<=ct[j]){ 
                        while(rh<=rt&&r[rt].data<=c[j][ch[j]].data)rt--;
                        r[++rt]={c[j][ch[j]].data,j};
                    }
                    if(rh<=rt)
                        dp[i][j]=max(dp[i][j],r[rh].data+a[i][j]-u);
                    if(ch[j]<=ct[j])
                        rt--;
                }
                if(dp[i][j]>=u){ 
                    while(ch[j]<=ct[j]&&c[j][ct[j]].data<=dp[i][j])ct[j]--;
                    c[j][++ct[j]]={ dp[i][j],i};
                }
                if(ch[j]<=ct[j]){ 
                    while(rh<=rt&&r[rt].data<=c[j][ch[j]].data)rt--;
                    r[++rt]={ c[j][ch[j]].data,j};
                }
            }
        }
        cout<<dp[n][m]<<"\n";
    }
    return 0;
}
