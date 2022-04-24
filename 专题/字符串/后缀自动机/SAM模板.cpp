#include<bits/stdc++.h>
using namespace std;
struct SAM{//maxn开2倍字符串
    int len[maxn],link[maxn],ch[maxn][26],last,tot,sz[maxn];//len指状态内最长长度
    int tax[maxn],rk[maxn];
    ll sum[maxn];
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
    int query(char *s){ //两串匹配 此处求的是最长公共子串
        int ans=0,p=1,nowlen=0,L=strlen(s+1);
        for(int i=1;i<=L;++i){
            int c=s[i]-'a';
            if(ch[p][c])nowlen++,p=ch[p][c];
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)nowlen=0,p=1;
                else{ 
                    nowlen=len[p]+1,p=ch[p][c];
                }
            }
            ans=max(ans,nowlen);
        }
        return ans;
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
}sam;
