#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
struct SAM{ 
    int len[maxn],link[maxn],ch[maxn][26],tot,last;
    ll ans1[maxn];
    void init(){ 
        tot=last=1;
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
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    ll solve1(int x){ 
        if(ans1[x])return ans1[x];
        for(int i=0;i<26;++i){ 
            if(ch[x][i])ans1[x]+=solve1(ch[x][i])+1;
        }
        return ans1[x];
    }
    ll solve2(){ 
        ll ans=0;
        for(int i=2;i<=tot;++i)ans+=len[i]-len[link[i]];
        return ans;
    }
}sam;
char s[maxn];
int main(){ 
    int len;
    scanf("%d",&len);
    scanf("%s",s+1);
    sam.init();
    for(int i=1;i<=len;++i)sam.extend(s[i]-'a');
    cout<<sam.solve1(1);
    //cout<<sam.solve2();
    return 0;
}
