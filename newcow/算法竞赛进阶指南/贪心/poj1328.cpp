#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,r;
const int maxn=1005;
pair<int,int>a[maxn];
struct P{ 
    double l,r;
    bool operator<(const P&a)const{ 
        return r<a.r;
    }
}b[maxn];
int main(){ 
    while(~scanf("%d%d",&n,&r)){ 
        if(!n&&!r)break;
        bool flag=1;
        for(int i=1;i<=n;++i){ 
            scanf("%d%d",&a[i].fi,&a[i].se);
            if(a[i].se>r)flag=0;
        }
        if(!flag){ 
            cout<<"-1"<<"\n";continue;
        }
        if(n==0||r==0){ 
            cout<<"-1"<<"\n";continue;
        }
        for(int i=1;i<=n;++i){ 
            double k=sqrt(r*r-a[i].se*a[i].se);
            b[i].l=a[i].fi-k;
            b[i].r=a[i].fi+k;   
        }
        sort(b+1,b+1+n);
        int ans=0;
        ans++;
        double pos=b[1].r;
        for(int i=2;i<=n;++i){ 
            if(b[i].l>pos){ 
                pos=b[i].r;ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
