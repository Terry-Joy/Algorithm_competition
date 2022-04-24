#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int u[maxn][maxn],mp[maxn][maxn],l[maxn][maxn],r[maxn][maxn],n,m,t;
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)scanf("%d",&mp[i][j]);
        for(int i=n;i>=2;--i)
            for(int j=1;j<=m;++j)
                if(mp[i][j]>=mp[i-1][j])mp[i][j]=1;
                else mp[i][j]=0;
        for(int i=1;i<=m;++i)mp[1][i]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){ 
                if(mp[i][j])
                    u[i][j]=l[i][j]=r[i][j]=1;
            }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){ 
                if(mp[i][j]&&mp[i-1][j])
                    u[i][j]=u[i-1][j]+1;
            }
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j){ 
                if(mp[i][j]&&mp[i][j-1])
                    l[i][j]=l[i][j-1]+1;
            }
        }
        for(int i=1;i<=n;++i){ 
            for(int j=m;j>=1;--j){ 
                if(mp[i][j]&&mp[i][j+1])
                    r[i][j]=r[i][j+1]+1;
            }
        }
        int ans=m;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j){ 
                if(mp[i][j]&&mp[i-1][j]){ 
                    l[i][j]=min(l[i][j],l[i-1][j]);
                    r[i][j]=min(r[i][j],r[i-1][j]);
                }
                ans=max(ans,(u[i][j]+1)*(l[i][j]+r[i][j]-1));
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)mp[i][j]=u[i][j]=l[i][j]=r[i][j]=0;
    }
    return 0;
}

