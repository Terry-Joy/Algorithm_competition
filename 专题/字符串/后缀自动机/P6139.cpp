#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
const int N=1e6+5;
struct Trie{ 
    int cnt,tr[N][26],fa[N],ch[N];
    Trie(){ cnt=1;}
    void insert(char*s){ 
        int p=1,L=strlen(s+1);
        for(int i=1;i<=L;++i){ 
            int c=s[i]-'a';
            if(!tr[p][c])tr[p][c]=++cnt,fa[cnt]=p,ch[cnt]=c;
            p=tr[p][c];
        }
    }
}trie;
struct GSAM{ 
    int tot,pos[maxn],link[maxn],len[maxn],ch[maxn][26];
    queue<int>q;
    GSAM(){ tot=1;}
    int insert(int c,int last){ 
        int cur=++tot,p=last;
        len[cur]=len[p]+1;
        while(p&&!ch[p][c])ch[p][c]=cur,p=link[p];
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                len[clone]=len[p]+1;
                while(p&&ch[p][c]==q)ch[p][c]=clone,p=link[p];
                link[clone]=link[q];link[q]=link[cur]=clone;
            }
        }
        return cur;
    }
    void build(){ 
        for(int i=0;i<26;++i)
            if(trie.tr[1][i])q.push(trie.tr[1][i]);
        pos[1]=1;
        while(!q.empty()){ 
            int x=q.front();q.pop();
            pos[x]=insert(trie.ch[x],pos[trie.fa[x]]);
            for(int i=0;i<26;++i)
                if(trie.tr[x][i])q.push(trie.tr[x][i]);
        }
    }
    void solve(){ 
        ll ans=0;
        for(int i=2;i<=tot;++i)ans+=len[i]-len[link[i]];
        cout<<ans;
    }
}gsam;
    
char s[N];
int main(){ 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%s",s+1),trie.insert(s);
    gsam.build();
    gsam.solve();
}
