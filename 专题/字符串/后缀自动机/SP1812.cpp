#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5;
struct SAM{//maxn开2倍
    int len[maxn],link[maxn],ch[maxn][26],last,tot,mx[maxn],mn[maxn],ans;//len指状态内最长长度
    vector<int>G[maxn];
    SAM(){ //link指向状态内最长字符串的最长的一个在另一个endpos类的后缀
        tot=last=1;//sz endpos大小
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;
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
            mx[x]=max(mx[x],min(mx[v],len[x]));
        }
        mn[x]=min(mn[x],mx[x]);
    }
    void init(){ 
        for(int i=1;i<=tot;++i)mn[i]=1e9;
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
    }
    void query(char*s){ 
        int L=strlen(s+1),p=1,nowlen=0;
        for(int i=1;i<=L;++i){ 
            int c=s[i]-'a';
            if(ch[p][c]){ 
                p=ch[p][c];nowlen++;
            }else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)p=1,nowlen=0;
                else nowlen=len[p]+1,p=ch[p][c];
            }
            mx[p]=max(nowlen,mx[p]);
        }
        dfs(1);
        for(int i=1;i<=tot;++i)mx[i]=0;
    }
    void solve(){ 
        for(int i=1;i<=tot;++i){ 
            if(mn[i]!=1e9)ans=max(ans,mn[i]);
        }
        cout<<ans;
    }
}sam;
char s[maxn],s1[maxn];
int ans,num=0;
int main(){
    scanf("%s",s+1);
    int L=strlen(s+1);
    for(int i=1;i<=L;++i)sam.extend(s[i]-'a');
    sam.init();
    while(~scanf("%s",s+1))
        sam.query(s);
    sam.solve();
    return 0;
}
