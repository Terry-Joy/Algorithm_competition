#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using P=pair<int,int>;
const int maxn=(1<<18)+10;
int n,a[maxn];
P f[maxn];
int main(){ 
    cin>>n;
    for(int i=0;i<(1<<n);++i)cin>>a[i],f[i].fi=a[i];
    for(int i=0;i<n;++i){ 
        for(int j=0;j<(1<<n);++j){ 
            if((1<<i)&j){ 
                if(f[j^(1<<i)].fi>f[j].fi){ 
                    f[j].se=f[j].fi;
                    f[j].fi=f[j^(1<<i)].fi;
                }else if(f[j^(1<<i)].fi>f[j].se){ 
                    f[j].se=f[j^(1<<i)].fi;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<(1<<n);++i){ 
        ans=max(ans,f[i].fi+f[i].se);
        cout<<ans<<"\n";
    }
    return 0;
}
