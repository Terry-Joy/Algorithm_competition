#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#define eb push_back
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int k;
char s[maxn];
struct SAM{
    vector<int>G[maxn]; 
    int tran(char w){ 
        if(w>='a'&&w<='z')return w-'a';
        return w-'A'+26;
    }
    int len[maxn],link[maxn],ch[maxn][53],sz[maxn],cnt[maxn],tot,last;
    ll ans;
    SAM(){ 
        last=tot=1;
    }
    void init(){ 
        ans=0;
        for(int i=1;i<=tot;++i)len[i]=link[i]=sz[i]=cnt[i]=0;
        for(int i=1;i<=tot;++i)G[i].clear();
        for(int i=1;i<=tot;++i)
            memset(ch[i],0,sizeof(ch[i]));
        tot=last=1;
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;
        len[cur]=len[p]+1;sz[cur]=1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
                link[clone]=link[q];link[q]=link[cur]=clone;
            }
        }
    }
    void dfs(int x){ 
        for(int i=0;i<G[x].size();++i){ 
            int v=G[x][i];
            dfs(v);
            sz[x]+=sz[v];
        }
    }
    void solve(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
    }
    void dfs1(int x){ 
        for(int i=0;i<G[x].size();++i){ 
            int v=G[x][i];
            dfs1(v);
            cnt[x]+=cnt[v];
        }
        int M=max(len[link[x]]+1,k);
        if(len[x]>=M)
            ans+=(ll)cnt[x]*sz[x]*(len[x]-M+1);
    }
    void query(char *s){ 
        int L=strlen(s+1),p=1,nowlen=0;
        for(int i=1;i<=L;++i){ 
            int c=tran(s[i]);
            if(ch[p][c])nowlen++,p=ch[p][c];
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)p=1,nowlen=0;
                else nowlen=len[p]+1,p=ch[p][c];
            }
            int M=max(len[link[p]]+1,k);
            if(nowlen>=M)
                ans+=(ll)sz[p]*(nowlen-M+1);
                cnt[link[p]]++;
        }
        dfs1(1);
        cout<<ans<<"\n";
    }
}sam;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>k&&k){ 
        cin>>(s+1);
        int L=strlen(s+1);
        for(int i=1;i<=L;++i)sam.extend(sam.tran(s[i]));
        cin>>(s+1);
        sam.solve();
        sam.query(s);
        sam.init();
    }
    return 0;
}
