#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int t,n,m;
int a[maxn],pos;
vector<int>num;
pair<int,double>cap[maxn];
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&n,&m);
        pos=0;
        num.clear();
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=n;i;--i){ 
            if(i!=a[i]){ 
                pos=i;break;
            }
        }
        for(int i=1;i<=m;++i){ 
            scanf("%d%lf",&cap[i].fi,&cap[i].se);
        }
        if(!pos){ 
            cout<<"1.000000"<<"\n";continue;
        }
        for(int i=1;i<=m;++i){ 
            if(cap[i].fi>=pos)num.push_back(i);
        }
        double del=1;
        for(auto&v:num){ 
            del=del*(1-cap[v].se);
        }
        printf("%.6lf\n",1-del);
    }
    return 0;
}
