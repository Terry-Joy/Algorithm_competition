#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct SAM{//maxn开2倍
    int len[maxn],link[maxn],ch[maxn][26],last,tot;
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
    int query(char *s){ 
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
}sam;
char s[maxn];
int main(){ 
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;++i)sam.extend(s[i]-'a');
    scanf("%s",s+1);
    cout<<sam.query(s);
    return 0;
}
