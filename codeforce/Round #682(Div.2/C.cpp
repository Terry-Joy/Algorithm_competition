//terryjoy 
#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define push_back pb
#define insert ins
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>PI;
int a[105][105];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t,n,m;
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)cin>>a[i][j];
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j){ 
                if((i+j)%2!=a[i][j]%2)
                    a[i][j]++;
            }
        }
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

