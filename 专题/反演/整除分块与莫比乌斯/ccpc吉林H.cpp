#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int mu[maxn],prime[maxn],t,n,m,k,a;
bool v[maxn];
ll cnt[maxn],cnt_ans[maxn],ans[maxn],tot;
void init(){ 
    mu[1]=1;
    for(int i=2;i<maxn;++i){ 
        if(!v[i])prime[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&prime[j]*i<maxn;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0) 
                break;
            mu[i*prime[j]]=-mu[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    init();
    cin>>t;
    while(t--){ 
        cin>>n>>m>>k;
        for(int i=1;i<=m;++i)ans[i]=cnt_ans[i]=cnt[i]=0;
        for(int i=1;i<=n;++i){ 
            cin>>a;cnt[a]++;
        }
        for(int i=1;i<=m;++i){ 
            for(int j=i;j<=m;j+=i){ 
                cnt_ans[i]+=cnt[j];
            }
        }
        for(int i=1;i<=m;++i){ 
            for(int j=i;j<=m;j+=i){ 
                ans[i]+=cnt_ans[j]*cnt_ans[j]*mu[j/i];
            }
        }
        for(int i=1;i<=k;++i){ 
            cin>>a;
            cout<<ans[a]<<"\n";
        }
    }
    return 0;
}
