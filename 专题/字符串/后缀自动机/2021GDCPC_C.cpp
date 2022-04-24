#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=6e5+5;
int dp[maxn];
struct SAM{//maxn开2倍
    int len[maxn],link[maxn],ch[maxn][10],last,tot,sz[maxn];//len指状态内最长长度
    vector<int>G[maxn];
    SAM(){ //link指向状态内最长字符串的最长的一个在另一个endpos类的后缀
        tot=last=1;//sz endpos大小
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;sz[cur]=1;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;//==len[p]+1的复制出来
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
        }
    }
    void init(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
        for(int i=1;i<=tot;++i)dp[len[i]]=max(dp[len[i]],sz[i]);
    }
}sam;
char s[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,k;
    cin>>n>>q;
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=n;++i){ 
        int c=s[i]-'1';
        sam.extend(c);
    }
    sam.init();
    for(int i=len-1;i>=1;--i)dp[i]=max(dp[i+1],dp[i]);
    for(int i=1;i<=q;++i){ 
        cin>>k;
        cout<<dp[k]<<"\n";
    }
    return 0;
}
