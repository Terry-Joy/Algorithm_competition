#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
const int M=130;
char s[maxn];
struct SA{ 
    int n,m,a[maxn],sa[maxn],rank[maxn],Height[maxn],tax[maxn],tp[maxn],k,mx=0,num,pos[maxn];
    void init(){ 
        scanf("%d",&num);
        for(int i=1;i<=num;++i){ 
            scanf("%s",s+1);
            int len=strlen(s+1);
            mx=max(mx,len);
            for(int j=1;j<=len;++j){ 
                a[++n]=s[j],pos[n]=i;
            }
            a[++n]='#'+i;
        }
        n--;
        m=(int)'z';
        //for(int i=1;i<=n;++i)putchar((char)a[i]);
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

        for(int i=1;i<=n;++i)cout<<Height[i]<<" "<<pos[sa[i]]<<"\n";
    }
    bool check(int x){ 
        int st=0;
        st|=(1<<(pos[sa[1]]-1));
        if(st==((1<<num)-1))return 1;
        for(int i=2;i<=n;++i){ 
            if(Height[i]<x){ 
                st=0;
                st|=(1<<(pos[sa[i]]-1));
            }else{ 
                st|=(1<<(pos[sa[i]]-1));
                if(st==((1<<num)-1))return 1;
            }
        }
        return 0;
    }
    void solve(){ 
        int l=0,r=mx;
        while(l<r){ 
            int mid=(l+r+1)>>1;
            if(check(mid))
                l=mid;
            else r=mid-1;
        }
        cout<<l;
    }
}sa;
int main(){ 
    sa.init();
    sa.Suffix();
    //sa.solve();
    return 0;
}
