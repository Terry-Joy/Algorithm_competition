#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct SA{ 
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn],H[maxn];
    //rk[i] [i,n]后缀排名 第一关键字 tp[i]第二关键字中,排名为i的数的位置
    //sa[i] 排名为i的后缀的位置 
    //ht[i] 排名为i和i-1的后缀的LCP
    //tax[i](基数排序辅助,多少个排名i)
    //H[i]=ht[rk[i]] [i,n]和它前一名的LCP
    void init(){ 
        scanf("%s",s+1);
        n=strlen(s+1);
        m=(int)'z';//最大字符ASCII码
    }
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
    void getht(){ 
        int j,k=0;
        for(int i=1;i<=n;ht[rk[i++]]=k)
            for(k=k?k-1:k,j=sa[rk[i]-1];a[i+k]==a[j+k];++k);
        for(int i=1;i<=n;++i)H[i]=ht[rk[i]];
    }
    void solve(){ 
        for(int i=1;i<=n;++i)cout<<sa[i]<<" ";
    }
}sa;
int main(){ 
    sa.init();
    sa.Suffix();
    sa.solve();
}
