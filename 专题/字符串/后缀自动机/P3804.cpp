#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
struct SAM{ 
    int len[maxn],link[maxn],ch[maxn][26],last,tot,sz[maxn],tax[maxn];
    int rk[maxn];
    void init(){ //一定记得
        tot=last=1;
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;sz[cur]=1;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[q]==len[p]+1)link[cur]=q;
            else{ 
                int clone=++tot;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                len[clone]=len[p]+1;
                link[clone]=link[q],link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    ll claSZ(int x){
        ll ans=0;
        for(int i=1;i<=tot;++i)tax[len[i]]++;
        for(int i=1;i<=x;++i)tax[i]+=tax[i-1];
        for(int i=1;i<=tot;++i)rk[tax[len[i]]--]=i;
        for(int i=tot;i>=1;--i){ 
            int now=rk[i];
            sz[link[now]]+=sz[now];
            if(sz[now]>1)ans=max(ans,(ll)sz[now]*len[now]);
        }
        return ans;
    }
}sam;
char s[maxn];
int main(){ 
    scanf("%s",s+1);
    int len=strlen(s+1);
    sam.init();
    for(int i=1;i<=len;++i)sam.extend(s[i]-'a');
    cout<<sam.claSZ(len);
}
