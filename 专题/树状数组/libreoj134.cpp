#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
const int maxn=4100;
ll d[4100][4100];
int op,a,b,c,f,k,n,m;
inline void add(int x,int y,int val){ 
    while(x<=n){ 
        int yy=y;
        while(yy<=m){ 
            d[x][yy]+=val;
            yy+=lowbit(yy);
        }
        x+=lowbit(x);
    }
}
ll ask(int x,int y){ 
    ll ans=0;
    while(x){ 
        int yy=y;
        while(yy){ 
            ans+=d[x][yy];
            yy-=lowbit(yy);
        }
        x-=lowbit(x);
    }
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(cin>>op){ 
        if(op==1){ 
            cin>>a>>b>>c>>f>>k;
            add(a,b,k);
            add(a,f+1,-k);
            add(c+1,b,-k);
            add(c+1,f+1,k);
        }else{ 
            cin>>a>>b;
            cout<<ask(a,b)<<"\n";
        }
    }
    return 0;
}
