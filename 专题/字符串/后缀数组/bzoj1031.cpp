#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct SA{ 
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn];
    int cmp(int*f,int x,int y,int w){ 
        return f[x]==f[y]&&f[x+w]==f[y+w];
    }
    void rsort(){ 
        for(int i=0;i<=m;++i)tax[i]=0;  
        for(int i=1;i<=n;++i)tax[rk[tp[i]]]++;
        for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
        for(int i=n;i>=1;--i)sa[tax[rk[tp[i]]]--]=tp[i];
    }
    void Suffix(){ 
        for(int i=1;i<=n;++i)a[i]=s[i];
        for(int i=1;i<=n;++i)rk[i]=a[i],tp[i]=i;
        rsort();
        for(int w=1,p=1,i;p<n;w+=w,m=p){ 
            for(p=0,i=n-w+1;i<=n;++i)tp[++p]=i;
            for(i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
            rsort(),swap(rk,tp),rk[sa[1]]=p=1;
            for(int i=2;i<=n;++i)
                rk[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
        }
    }
    void solve(){ 
        scanf("%s",s+1);
        n=2*strlen(s+1);
        int len=strlen(s+1)+1;
        for(int i=len;i<=n;++i){ 
            s[i]=s[i-len+1];
        }
        //for(int i=1;i<=n;++i)
          //  putchar(s[i]);
        m=200;//最大字符ASCII码
        Suffix();
        for(int i=1;i<=n;++i)if(sa[i]<=len-1)putchar(s[sa[i]+len-2]);
    }
}sa;
int main(){ 
    sa.solve();
    return 0;
}

