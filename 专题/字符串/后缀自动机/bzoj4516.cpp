#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+5;
struct SAM{ 
    int len[maxn],link[maxn],last,tot;
    map<int,int>ch[maxn];
    ll ans;
    SAM(){ 
        tot=last=1;
        ans=0;
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;
        len[cur]=len[p]+1;
        for(;p&&ch[p].find(c)==ch[p].end();p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;
                ch[clone]=ch[q];
                len[clone]=len[p]+1;
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
        ans+=len[cur]-len[link[cur]];
    }
}sam;
int main(){ 
    int n;
    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;++i){ 
        scanf("%d",&x);
        sam.extend(x);
        cout<<sam.ans<<"\n";
    }
    return 0;
}
