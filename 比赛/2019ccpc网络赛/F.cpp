#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
bool v[maxn],out[maxn];
int a[maxn],cnt,b[maxn],n,m;
int main(){ 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=m;++i){ 
        int x;
        scanf("%d",&x);
        b[++cnt]=x;
        v[x]=1;
    }
    for(int i=cnt;i;--i){ 
        if(!out[b[i]])cout<<b[i]<<" ",out[b[i]]=1;
    }
    for(int i=1;i<=n;++i){ 
        if(!v[a[i]])cout<<a[i]<<" ";
    }
    return 0;
}
