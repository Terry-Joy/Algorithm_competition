#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
const int maxn=1e6+5;
struct SAM{ 
    int len[maxn],link[maxn],ch[maxn][26],last,tot,sz[maxn];//len指状态内最长长度
    vector<int>G[maxn];
    ll ans;
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
            ans+=(ll)sz[x]*sz[v]*len[x];
            sz[x]+=sz[v];
        }
    }
    ll solve(){ 
        for(int i=2;i<=tot;++i)G[link[i]].pb(i);
        dfs(1);
        return ans;
    }
}sam;
char s[maxn];
int main(){ 
    scanf("%s",s);
    int n=strlen(s);
    for(int i=n-1;i>=0;--i)sam.extend(s[i]-'a');
    int p=1;
    cout<<(ll)n*(n+1)*(n-1)/2-2*sam.solve()<<"\n";
    return 0;
}
