#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,m,ans[maxn][maxn];
int main(){ 
    cin>>n>>m;
    for(int i=1;i<=m;++i){ 
        ans[1][i]=((i+1)/2)%2;
    }
    for(int i=2;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans[i][j]=1-ans[i-1][j];
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j)
            cout<<ans[i][j];
        puts("");
    }
    return 0;
}
