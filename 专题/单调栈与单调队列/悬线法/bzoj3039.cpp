#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,m;
int mp[maxn][maxn],u[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
int main(){ 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            char s[2];
            scanf("%s",s);
            mp[i][j]=(s[0]=='F');
        }
    }
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            if(mp[i][j])
                u[i][j]=l[i][j]=r[i][j]=1;
        }
    }
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            if(mp[i-1][j]&&mp[i][j])
                u[i][j]=u[i-1][j]+1;
        }
    }
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            if(mp[i][j-1]&&mp[i][j])
                l[i][j]=l[i][j-1]+1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){ 
        for(int j=m;j;--j){ 
            if(mp[i][j+1]&&mp[i][j])
                r[i][j]=r[i][j+1]+1;
        }
    }
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            if(mp[i][j]&&mp[i-1][j]){ 
                l[i][j]=min(l[i][j],l[i-1][j]);
                r[i][j]=min(r[i][j],r[i-1][j]);
            }
            ans=max(ans,3*u[i][j]*(l[i][j]+r[i][j]-1));
        }
    }
    cout<<ans;
    return 0;
}
