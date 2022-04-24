#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=4e3+5;
struct SAM{
    int len[maxn],link[maxn],tot,tax[maxn],last,ch[maxn][26],rk[maxn],mx[maxn],mn[maxn];
    SAM(){ 
        tot=last=1;
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;
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
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void rsort(int x){ 
        for(int i=1;i<=tot;++i)tax[len[i]]++;
        for(int i=1;i<=x;++i)tax[i]+=tax[i-1];
        for(int i=1;i<=tot;++i)rk[tax[len[i]]--]=i;
    }
    void match(char *s){ 
        int L=strlen(s),p=1,nowlen=0;
        for(int i=0;i<L;++i){ 
            int c=s[i]-'a';
            if(ch[p][c])p=ch[p][c],nowlen++;
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)nowlen=0,p=1;
                else nowlen=len[p]+1,p=ch[p][c];
            }
            mx[p]=max(mx[p],nowlen);
        }
        for(int i=tot;i;--i){ 
            int now=rk[i];
            mx[link[now]]=max(mx[link[now]],min(mx[now],len[link[now]]));
        }
        for(int i=1;i<=tot;++i)mn[i]=min(mn[i],mx[i]),mx[i]=0;
    }
    void init(){ 
        memset(mx,0,sizeof(mx));
        memset(mn,INF,sizeof(mn));
    }
    int ask(){ 
        return *max_element(mn+1,mn+1+tot);
    }
}sam;
int n;
char s[maxn];
int main(){ 
    sam.init();
    scanf("%d",&n);
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;++i)sam.extend(s[i]-'a');
    sam.rsort(len);
    for(int i=1;i<n;++i){ 
        scanf("%s",s);
        sam.match(s);
    }
    cout<<sam.ask();
    return 0;
}
