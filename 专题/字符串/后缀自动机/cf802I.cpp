#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const int maxn=2e5+5;
struct SAM{ 
    int len[maxn],sz[maxn],tot,link[maxn],ch[maxn][26],last;
    int rk[maxn],tax[maxn];
    void init(int x){ 
        for(int i=0;i<=x;++i)tax[i]=0;
        for(int i=1;i<=tot;++i)sz[i]=0;
        for(int i=1;i<=tot;++i)
            for(int j=0;j<=26;++j)ch[i][j]=0;
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
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void calSZ(int x){ 
        for(int i=1;i<=tot;++i)tax[len[i]]++;
        for(int i=1;i<=x;++i)tax[i]+=tax[i-1];
        for(int i=1;i<=tot;++i)rk[tax[len[i]]--]=i;
        for(int i=tot;i>=1;--i){ 
            int now=rk[i];
            sz[link[now]]+=sz[now];
        }
    }   
    ll solve(){ 
        ll ans=0;
        for(int i=2;i<=tot;++i){ 
            ans+=(ll)sz[i]*sz[i]*(len[i]-len[link[i]]);      
        }
        return ans;
    }
}sam;
char s[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){ 
        scanf("%s",s+1);
        int len=strlen(s+1);
        sam.init(len);
        for(int i=1;i<=len;++i)sam.extend(s[i]-'a');
        sam.calSZ(len);
        cout<<sam.solve()<<"\n";
    } 
    return 0;
}
