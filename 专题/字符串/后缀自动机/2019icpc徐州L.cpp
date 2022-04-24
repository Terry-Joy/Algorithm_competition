#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=6e5+5;
vector<int>G[maxn],G2[maxn];
int n,Q,pos[maxn];
char val[maxn];
struct GSAM{ 
    int link[maxn],ch[maxn][26],tot,len[maxn],fa[maxn][24],sz[maxn];
    queue<int>q;
    GSAM(){ tot=1;}
    /*int extend(int c,int last){ 
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
    }*/
    int extend(int c,int last){ 
        if(ch[last][c]&&len[last]+1==len[ch[last][c]])return ch[last][c];
        int cur=++tot,p=last,flag=0;
        int clone;
        len[cur]=len[p]+1;
        while(p&&!ch[p][c])ch[p][c]=cur,p=link[p];
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                if(len[p]+1==len[cur])flag=1;
                clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                while(p&&ch[p][c]==q)ch[p][c]=clone,p=link[p];
                link[clone]=link[q];link[q]=link[cur]=clone;
            }
        }
        return flag?clone:cur;
    }
    void dfs(int x){ 
        for(auto&v:G[x]){ 
            dfs(v);
            sz[x]+=sz[v];
        }
    }
    void build(){ 
        q.push(0);
        pos[0]=1;
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(auto&v:G2[x]){ 
                pos[v]=extend(val[v]-'A',pos[x]);
                sz[pos[v]]++;
                q.push(v);
            }
        }
    }
    void solve(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
        for(int i=1;i<=tot;++i)fa[i][0]=link[i];
        for(int j=1;j<=22;++j)
            for(int i=1;i<=tot;++i)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        int x,L;
        for(int i=1;i<=Q;++i){ 
            cin>>x>>L;
            int ps=pos[x];
            for(int j=22;j>=0;--j){ 
                if(len[fa[ps][j]]>=L)
                    ps=fa[ps][j];
            }
            cout<<sz[ps]<<"\n";
        }
    }

}gsam;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>Q;
    cin>>(val+1);
    int x;
    G2[0].eb(1);
    for(int i=2;i<=n;++i){ 
        scanf("%d",&x);
        G2[x].eb(i);
    }
    pos[0]=1;
    gsam.build();
    gsam.solve();
    return 0;
}


