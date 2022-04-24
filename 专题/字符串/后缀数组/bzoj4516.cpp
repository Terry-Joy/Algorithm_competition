#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct SA{ 
    int s[maxn],d[maxn],u[maxn],b[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn];
    ll ans[maxn];
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
    }    
    void init(){ 
        scanf("%d",&n);
        for(int i=n;i;--i)scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+1+n);
        m=unique(b+1,b+1+n)-(b+1);
        for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+m,a[i])-b;
        Suffix();
        getht();
    }
    void solve(){ 
        for(int i=1;i<=n;++i)u[i]=i-1,d[i]=i+1;
        ll res=0;
        for(int i=1;i<=n;++i)
            res+=n+1-sa[i]-ht[i];
        for(int i=1;i<=n;++i){ 
            ans[i]=res;
            int pos=rk[i],j=d[pos];
            res-=n+1-sa[pos]-ht[pos];
            res-=n+1-sa[j]-ht[j];
            ht[j]=min(ht[j],ht[pos]);
            res+=n+1-sa[j]-ht[j];
            d[u[pos]]=j,u[j]=u[pos];
        }
        for(int i=n;i;--i)cout<<ans[i]<<"\n";

    }
}sa;
int main(){
    sa.init();
    sa.solve();
}
