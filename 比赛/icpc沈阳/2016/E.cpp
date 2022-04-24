#include<bits/stdc++.h>

using namespace std;
vector<int>mp[105];
int G[105][105],n,m,a[15],cnt,t,s,ans=0;
void dfs(int x,int sum){ 
    if(sum==s){ 
        ans++;
        return;
    }
    for(auto&v:mp[x]){ 
        bool flag=1;
        for(int i=1;i<=sum;++i)
            if(!G[a[i]][v]){ 
                flag=0;break;
            }
        if(flag){ 
            a[++cnt]=v;
            dfs(v,sum+1);
            --cnt;
        }
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        ans=0;
        cin>>n>>m>>s;
        for(int i=1;i<=n;++i)mp[i].clear();
        memset(G,0,sizeof(G));
        for(int i=1;i<=m;++i){ 
            int x,y;
            cin>>x>>y;
            G[x][y]=1;
            G[y][x]=1;
            mp[x].push_back(y);
        }
        for(int i=1;i<=n;++i){
            cnt=0;
            a[++cnt]=i;
            dfs(i,1);
        }
        cout<<ans<<"\n";
    } 
    return 0;
}
