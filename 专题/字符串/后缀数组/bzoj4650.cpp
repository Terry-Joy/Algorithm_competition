#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3e4+5;
int Log[maxn];
struct SA{ 
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn],mn[maxn][17];
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
    void init(){ 
        memset(mn,0,sizeof(mn));
        for(int i=0;i<=n;++i)a[i]=sa[i]=rk[i]=ht[i]=tax[i]=tp[i]=0;
    }
    void getht(){ 
        int j,k=0;
        for(int i=1;i<=n;ht[rk[i++]]=k)
            for(k=k?k-1:k,j=sa[rk[i]-1];a[i+k]==a[j+k];++k);
    }    
    void RMQ(){ 
        for(int i=1;i<=n;++i)mn[i][0]=ht[i];
        for(int j=1;(1<<j)<=n;++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
    }
    void solve(int x){ 
        n=x;//结束符！不能直接strlen
        m=(int)'z';//最大字符ASCII码
        Suffix();
        getht();
        RMQ();
    }
    int query(int l,int r){ 
        l=rk[l],r=rk[r];
        if(l>r)swap(l,r);
        l++;
        int k=Log[r-l+1];
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
    }
}pre,suf;
int f[maxn],g[maxn];
int main(){ 
    Log[1]=0;
    for(int i=2;i<maxn;++i)
        Log[i]=Log[i/2]+1;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",suf.s+1);
        int len=strlen(suf.s+1);
        for(int i=1;i<=len;++i)pre.s[i]=suf.s[len+1-i]; 
        pre.solve(len);suf.solve(len);
        for(int i=1;i<=len/2;++i){ 
            for(int j=1;j+i<=len;j+=i){ 
                int fi=j,se=j+i;
                int lcp=min(suf.query(fi,se),i),lcs=min(pre.query(len+1-se,len+1-fi),i);//原序列和排序后的序列分清楚!
                int del=lcp+lcs-i;
                if(del>0){ 
                    f[se+lcp-del]++;f[se+lcp]--;
                    g[fi-lcs+del+1]--;g[fi-lcs+1]++;
                }
            }
        }
        ll ans=0;
        for(int i=2;i<=len;++i)
            f[i]+=f[i-1],g[i]+=g[i-1];
        for(int i=1;i<len;++i)
            ans+=(ll)f[i]*g[i+1];
        pre.init();suf.init();
        for(int i=0;i<=len+1;++i)f[i]=g[i]=0;//差分到len+1可能有影响
        cout<<ans<<"\n";
    }
    return 0;
}
