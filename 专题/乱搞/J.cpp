#include<bits/stdc++.h>

using namespace std;
const int maxn=1005;
int dis[maxn][maxn],n;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){ 
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                cin>>dis[i][j];
        int d=1e6,cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){ 
                if(i==j)continue;
                if(dis[i][j]==d)cnt++;
                else if(dis[i][j]<d){ 
                    cnt=1;
                    d=dis[i][j];
                }
            }
        cout<<cnt/2<<endl;
    }
    return 0;
}
