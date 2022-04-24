#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+100;
const int maxm=1e5+5;
int M=1e4;
struct SA{
    struct Q{ 
        int l,r,id;
        bool operator<(const Q&a)const{ 
            return r<a.r;
        }
    }q[maxm];
    struct BIT{ 
        int M;
        #define lowb(i) (i&(-i))
        int c[maxn];
        void init(int x){ M=x;}
        void add(int x,int val){ 
            for(int i=x;i<=M;i+=lowb(i))
                c[i]+=val;
        }
        int ask(int x){ 
            int ans=0;
            for(int i=x;i;i-=lowb(i))
                ans+=c[i];
            return ans;
        }
    }bit;
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn],pos[maxn],qu,len[maxm];
    int ans1[maxm],ans2[maxm],pre[maxn],col[maxm],num1,num2,mn[maxn][23],Log[maxn],head[maxm];
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
    void getlr(){ 
        for(int i=1;i<=num2;++i){ 
            int lim=len[i],ps=rk[head[i]];
            int l=0,r=ps;
            bool f=0;
            while(l<r){ 
                int mid=(l+r+1)>>1;
                if(query(mid,ps)<lim){ 
                    l=mid,f=1;
                }else
                    r=mid-1;
            }
            q[i].l=(f?l:1);
            l=ps+1,r=n+1;
            f=0;
            while(l<r){ 
                int mid=l+r>>1;
                if(query(ps,mid)<lim){ 
                    r=mid;f=1;
                }else
                    l=mid+1;
            }
            q[i].r=(f?r-1:n);
        }
        for(int i=1;i<=num2;++i)q[i].id=i,bit.add(q[i].l,1);
        for(int i=1;i<=n;++i){ 
            int ps=pos[sa[i]];
            if(ps<=0)continue;
            if(!col[ps])col[ps]=i;
            else pre[i]=col[ps],col[ps]=i;
        }
    }
    void RMQ(){ 
        for(int i=1;i<=n;++i)mn[i][0]=ht[i];
        for(int j=1;(1<<j)<=n;++j){ 
            for(int i=1;i+(1<<j)-1<=n;++i)
                mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
        Log[1]=0;
        for(int i=2;i<=n+1;++i)
            Log[i]=Log[i/2]+1;
    }
    int query(int l,int r){ 
        int k=Log[r-l+1];
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
    }
    void solve(){ 
        sort(q+1,q+1+num2);
        int now=1;
        for(int i=1;i<=num2;++i){ 
            while(now<=q[i].r){ 
                if(pos[sa[now]]<=0){ 
                    now++;continue;
                }
                ans2[pos[sa[now]]]+=bit.ask(now)-bit.ask(pre[now]);
                now++;
            }       
            bit.add(q[i].l,-1);
        }
        now=1;
        for(int i=1;i<=num2;++i){ 
            while(now<=q[i].r){ 
                if(pos[sa[now]]<=0){ 
                    now++;continue;
                }
                if(!pre[now])bit.add(now,1);
                else bit.add(pre[now],-1),bit.add(now,1);
                now++;
            }
            ans1[q[i].id]=bit.ask(q[i].r)-bit.ask(q[i].l-1);
        }
    }
    void init(){ 
        int x,c;
        scanf("%d%d",&num1,&num2);
        for(int i=1;i<=num1;++i){ 
            scanf("%d",&x);
            for(int j=1;j<=x;++j){ 
                scanf("%d",&c);
                a[++n]=c;pos[n]=i;
            }
            a[++n]=++M;
            scanf("%d",&x);
            for(int j=1;j<=x;++j){ 
                scanf("%d",&c);
                a[++n]=c;pos[n]=i;
            }
            a[++n]=++M;
        }
        for(int i=1;i<=num2;++i){ 
            scanf("%d",&len[i]);
            head[i]=n+1;
            for(int j=1;j<=len[i];++j){ 
                scanf("%d",&c);
                a[++n]=c;pos[n]=-i;
            }
            a[++n]=++M;
        }
        bit.init(n);
        m=M+1;
        Suffix();
        getht();
        RMQ();
        getlr();
        solve();
        for(int i=1;i<=num2;++i)cout<<ans1[i]<<"\n";
        for(int i=1;i<=num1;++i)cout<<ans2[i]<<" ";
    }
}sa;
int main(){ 
    sa.init();
    return 0;
}
