#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll=long long;
const int N=1e5+5;
const int maxn=2e5+5;
vector<int>G[N];
int col[N],deg[N];
struct GSAM{ 
    int link[maxn*20],ch[maxn*20][10],tot,len[maxn*20];
    GSAM(){ tot=1;}
    int extend(int c,int last){ 
        if(ch[last][c]){ 
            int p=last,q=ch[p][c];
            if(len[p]+1==len[q])return q;
            else{ 
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                while(p&&ch[p][c]==q)ch[p][c]=clone,p=link[p];
                link[clone]=link[q];link[q]=clone;
                return clone; 
            }
        }
        int cur=++tot,p=last;
        len[cur]=len[p]+1;
        while(p&&!ch[p][c])ch[p][c]=cur,p=link[p];
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[q]==len[p]+1)link[cur]=q;
            else{ 
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                while(p&&ch[p][c]==q)ch[p][c]=clone,p=link[p];
                link[clone]=link[q];link[q]=link[cur]=clone;
            }
        }
        return cur;
    }
    ll solve(){ 
        ll ans=0;
        for(int i=2;i<=tot;++i)ans+=len[i]-len[link[i]];
        return ans;
    }
    void dfs(int x,int fa,int fap){ 
        int xfa=extend(col[x],fap);
        for(auto&v:G[x]){ 
            if(v==fa)continue;
            dfs(v,x,xfa);
        }
    }
}gsam;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;++i)cin>>col[i];
    int u,v;
    for(int i=1;i<n;++i){ 
        cin>>u>>v;
        G[u].eb(v);G[v].eb(u);
        deg[u]++;deg[v]++;
    }
    for(int i=1;i<=n;++i){ 
        if(deg[i]==1)gsam.dfs(i,0,1);
    }
    cout<<gsam.solve();
    return 0;
}
