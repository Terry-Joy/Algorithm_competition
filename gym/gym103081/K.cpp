#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=6e5+10;
char s[maxn];
struct SAM{ 
    vector<int>G[maxn];
    int len[maxn],link[maxn],ch[maxn][26],last,tot,pos[maxn],sz[maxn];
    SAM(){ tot=last=1;}
    void extend(int c,int id){ 
        int cur=++tot,p=last;last=cur;
        sz[cur]=1;pos[cur]=id;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                len[clone]=len[p]+1;
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void dfs(int x){ 
        for(auto&v:G[x]){ 
            dfs(v);
            sz[x]+=sz[v];
            pos[x]=min(pos[x],pos[v]);
        }
    }
    void solve(){
        for(int i=2;i<=tot;++i)if(!pos[i])pos[i]=1e9;
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
        int mn=1e9,ans=0;
        for(int i=2;i<=tot;++i){ 
            if(sz[i]==1){ 
                if(len[link[i]]+1<mn){ 
                    mn=len[link[i]]+1;
                    ans=pos[i]-mn+1;
                }
            }
        }
        for(int i=ans;i<=ans+mn-1;++i)cout<<s[i];
    }
}sam;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;++i)sam.extend(s[i]-'A',i);
    sam.solve();
    return 0;
}
