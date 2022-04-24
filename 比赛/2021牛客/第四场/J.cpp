#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef double db;
db sum[maxn];
int n,m,x,y,a[maxn],b[maxn];
db tmp[maxn];
bool check(db mid,int*a,int f,int len){ 
    for(int i=1;i<=len;++i)tmp[i]=a[i]-mid;
    for(int i=1;i<=len;++i)sum[i]=sum[i-1]+tmp[i];
    db mn=1e10,mx=-1e10;
    for(int i=f;i<=len;++i){ 
        mn=min(mn,sum[i-f]);
        mx=max(mx,sum[i]-mn);
    }
    return mx>=0;
}
int main(){ 
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=m;++i)scanf("%d",&b[i]);
    db l=0,r=1e5,mid;
    db ans=0;
    for(int i=1;i<=100;++i){ 
        mid=(l+r)/2.0;
        if(check(mid,a,x,n))l=mid;
        else r=mid;
    }
    ans+=mid;
    l=0,r=1e5;
    for(int i=1;i<=80;++i){ 
        mid=(l+r)/2.0;
        if(check(mid,b,y,m))l=mid;
        else r=mid;
    }
    ans+=mid;
    printf("%.10f",ans);
    return 0;
}
