#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int deg[maxn],t,n,f[maxn];
queue<int>q;
int main(){
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i)deg[i]=0;
        for(int i=1;i<=n;++i)scanf("%d",&f[i]),deg[f[i]]++;
        for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
        while(!q.empty()){ 
            int x=q.front();q.pop();
            if(--deg[f[x]]==0)
                q.push(f[x]);
        }
        ll sum1=-1,sum2=-1;
        bool flag=1;
        for(int i=1;i<=n;++i){ 
            if(!deg[i])continue;
            ll x1=0,x2=0;
            for(;deg[i];i=f[i]){ 
                x1+=i;
                x2++;
                deg[i]=0;
            }
            if(sum1==-1){ 
                sum1=x1;
                sum2=x2;
            }else{ 
                if(sum1*x2!=sum2*x1){ 
                    flag=0;
                    break;
                }
            }
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}
