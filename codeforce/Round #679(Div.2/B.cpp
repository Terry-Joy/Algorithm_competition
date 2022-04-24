#include<bits/stdc++.h>

using namespace std;
int t,n,m,a,b,row[510][510],col[510][510],ans[510][510];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>row[i][j];
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                cin>>col[i][j];
        for(int i=1;i<=n;++i){ 
            int tmp;
            for(int j=1;j<=n;++j)
                for(int k=1;k<=m;++k)
                    if(row[j][k]==col[1][i]){ 
                        tmp=j;break;
                    }
            for(int j=1;j<=m;++j)
                ans[i][j]=row[tmp][j];
        }
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j)
                cout<<ans[i][j]<<" ";
        cout<<"\n";
        }
    }
    return 0;
}
