#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
struct SA{//sa字符转后不能有负数(计数排序）
    int n,m,a[maxn],sa[maxn],rank[maxn],Height[maxn],tax[maxn],tp[maxn];
    void init(){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i){ 
            a[i]=a[i+1]-a[i];
            a[i]+=88;
        }
        n--;
        m=180;
    }
    int cmp(int*f,int x,int y,int w){ 
        return f[x]==f[y]&&f[x+w]==f[y+w];
    }
    void rsort(){ 
        for(int i=0;i<=m;++i)tax[i]=0;
        for(int i=1;i<=n;++i)tax[rank[tp[i]]]++;
        for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
        for(int i=n;i;--i)sa[tax[rank[tp[i]]]--]=tp[i];
    }
    void Suffix(){ 
        for(int i=1;i<=n;++i)rank[i]=a[i],tp[i]=i;
        rsort();
        for(int w=1,p=1,i;p<n;w+=w,m=p){ 
            for(p=0,i=n-w+1;i<=n;++i)tp[++p]=i;
            for(i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
            rsort(),swap(rank,tp),rank[sa[1]]=p=1;
            for(int i=2;i<=n;++i)
                rank[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
        }
        int j,k=0;
        for(int i=1;i<=n;Height[rank[i++]]=k)
            for(k=k?k-1:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
        Height[n+1]=-1;
    }
    bool check(int x){ 
        int mn=sa[1],mx=sa[1];
        for(int i=2;i<=n+1;++i){ 
            if(Height[i]<x){
                if(mx-mn-1>=x){ //差分后相差1
                    return 1;
                } 
                mn=mx=sa[i];
            }else{ 
                mn=min(mn,sa[i]);
                mx=max(mx,sa[i]);
            }
        }
        return 0;
    }
    void solve(){ 
        int l=-1,r=n;
        while(l<r){ 
            int mid=(l+r+1)>>1;
            if(check(mid))
                l=mid;
            else r=mid-1;
        }
        l++;
        cout<<(l<5?0:l);
    }
}sa;
int main(){ 
    sa.init();
    sa.Suffix();
    /*for(int i=1;i<=sa.n;++i){ 
        cout<<sa.sa[i]<<" "<<sa.Height[i]<<"\n";
    }*/
    sa.solve();
    return 0;
}
