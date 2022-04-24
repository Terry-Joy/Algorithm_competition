#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int t,n,a[maxn],dis[maxn],pre[maxn],mx=0,cnt[maxn];
int main(){
    scanf("%d",&t);
    while(t--){ 
        mx=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),mx=max(mx,a[i]);
        memset(dis,0,sizeof(dis));
        memset(cnt,0,sizeof(cnt));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;++i){ 
            dis[a[i]]=max(dis[a[i]],i-pre[a[i]]); 
            pre[a[i]]=i;
        }
        for(int i=1;i<=n;++i)
            dis[a[i]]=max(n-pre[a[i]]+1,dis[a[i]]);
        for(int i=1;i<=n;++i){ 
            if(!cnt[dis[i]])
                cnt[dis[i]]=i;
        }
        int ans=-1;
        for(int i=1;i<=n;++i){ 
            if(ans==-1&&cnt[i]==0){ 
                cout<<ans<<" ";
            }else if(ans==-1){ 
                ans=cnt[i];
                cout<<ans<<" ";
            }else if(!cnt[i]){ 
                cout<<ans<<" ";
            }else{ 
                ans=min(ans,cnt[i]);
                cout<<ans<<" ";
            }
        }
        puts("");
    }
    return 0;
}
