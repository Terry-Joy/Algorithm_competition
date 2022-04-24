#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+5;
int t,k;
struct SAM{ 
    int len[maxn],tot,last,sz[maxn],link[maxn],ch[maxn][26],tax[maxn],rk[maxn],cnt;
    ll sum[maxn];
    char ans[maxn];
    SAM(){ 
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
                link[clone]=link[q];link[cur]=link[q]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void calSZ(int x){
        for(int i=1;i<=tot;++i)tax[len[i]]++;
        for(int i=1;i<=x;++i)tax[i]+=tax[i-1];
        for(int i=1;i<=tot;++i)rk[tax[len[i]]--]=i;
        for(int i=tot;i;--i){ 
            int now=rk[i];
            sz[link[now]]+=sz[now];
        }
        sz[1]=0;
    }
    void calSum(){//sum[i] sam上经过从某字符出发 经过i结点的子串数量 
        //看题意initsum
        for(int i=2;i<=tot;++i)sum[i]=sz[i];
        for(int i=tot;i>=1;--i)
            for(int j=0;j<26;++j){ 
                int now=rk[i];//记得calSZ先算rk
                if(ch[now][j])sum[now]+=sum[ch[now][j]];
            }
    }
    void solve(int x,int k){
        if(k<=sz[x])return;
        k-=sz[x];
        for(int i=0;i<26;++i){ 
            if(!ch[x][i])continue;
            if(sum[ch[x][i]]<k){ k-=sum[ch[x][i]];continue;}
            putchar(i+'a');
            solve(ch[x][i],k);
            return;
        }
    }
}sam;
char s[maxn];
int main(){ 
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;++i)sam.extend(s[i]-'a');
    scanf("%d%d",&t,&k);
    sam.calSZ(len);
    if(!t)
        for(int i=2;i<=sam.tot;++i)sam.sz[i]=1;
    sam.calSum();
    if(sam.sum[1]<k)puts("-1");
    else sam.solve(1,k);
}
