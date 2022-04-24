#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e6+6;
int x[maxn],n,m,q,pi,ki;
int main(){ 
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i)scanf("%d",&x[i]);
    for(int i=1;i<=q;++i){ 
        scanf("%d%d",&pi,&ki);
        ll d=1ll*pi*x[ki];
        ll zhou=d/m;
        d=d-zhou*m;
        if(zhou&1)cout<<m-d<<"\n";
        else cout<<d<<"\n";
    }
    return 0;
}
