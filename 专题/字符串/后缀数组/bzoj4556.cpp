#include <bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=1e5+5;
const int N=maxn*32;
int tot,lc[N],rc[N],sum[N],rt[maxn],a,b,c1,d,q;
void pushUp(int p){ 
    sum[p]=sum[ls]+sum[rs];
}
void update(int q,int&p,int l,int r,int x){ 
    p=++tot;
    ls=lc[q],rs=rc[q],sum[p]=sum[q];
    if(l==r){ 
        sum[p]++;return;
    }
    int mid=l+r>>1;
    if(x<=mid)update(lc[q],lson,x);
    else update(rc[q],rson,x);
    pushUp(p);
}
int query(int q,int p,int l,int r,int L,int R){ 
    if(L<=l&&r<=R)return sum[p]-sum[q];
    int mid=l+r>>1,ans=0;
    if(L<=mid)ans+=query(lc[q],lson,L,R);
    if(R>mid)ans+=query(rc[q],rson,L,R);
    return ans;
}
struct SA{ 
    int s[(maxn<<1)+5],sa[maxn+5],rk[maxn+5],c[maxn+5],p[maxn+5],tmp[maxn+5],n,m,ht[maxn];
    char str[maxn+5]; bool t[(maxn<<1)+5];
    int mn[maxn][18],Log[maxn];
    #define Ar(x,a) sa[p[s[x]]a]=x
    void IS(int*s,int*s1,int n1,int n,int m,bool*t){
	    memset(sa+1,0,n<<2);memset(c+1,0,m<<2);
        for(int i=1;i<=n;++c[s[i++]]);
	    for(int i=2;i<=m;i++) c[i]+=c[i-1]; 
        memcpy(p+1,c+1,m<<2); 
        for(int i=n1;i;Ar(s1[i],--),i--);
	    for(int i=1;i<=m;i++) p[i]=c[i-1]+1; 
        for(int i=1;i<=n;sa[i]>1&&t[sa[i]-1]?Ar(sa[i]-1,++):0,i++);
	    memcpy(p+1,c+1,m<<2);
        for(int i=n;i;sa[i]>1&&!t[sa[i]-1]?Ar(sa[i]-1,--):0,i--);
    }
    void SAIS(int s[], bool t[], int tmp[], int n, int m){
	    int n1=0,m1=rk[1]=0,*s1=s+n;t[n]=0;
	    for(int i=n-1;i;t[i]=s[i]^s[i+1]?s[i]>s[i+1]:t[i+1],i--);
	    for(int i=2;i<=n;rk[i]=t[i-1]&&!t[i]?tmp[++n1]=i,n1:0,i++); 
        IS(s,tmp,n1,n,m,t);
	    for(int i=1,x,y=0;i<=n;i++) if(x=rk[sa[i]]){
		    if(m1<=1||tmp[x+1]-tmp[x]!=tmp[y+1]-tmp[y]) ++m1;
		    else for(int a=tmp[x],b=tmp[y];a<=tmp[x+1];a++,b++) if((s[a]<<1|t[a])^(s[b]<<1|t[b])){++m1;break;}
		    s1[y=x]=m1;
	    } 
	    if(m1<n1) SAIS(s1,t+n,tmp+n1,n1,m1); 
	    else for(int i=1;i<=n1;sa[s1[i]]=i,i++);
	    for(int i=1;i<=n1;s1[i]=tmp[sa[i]],i++); 
	    IS(s,s1,n1,n,m,t);
    }
    void MakeSA(){ 
    	--n; 
        for(int i=1;i<=n;i++) sa[i]=sa[i+1],rk[sa[i]]=i;
    }
    void getHt(){
	    for(int i=1,k=0;i<=n;ht[rk[i]]=k,i++,k&&--k) 
	    	for(int j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
    }
    void RMQ(){ 
        for(int i=1;i<=n;++i)mn[i][0]=ht[i];
        for(int j=1;(1<<j)<=n;++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        Log[1]=0;
        for(int i=2;i<=n+1;++i)
            Log[i]=Log[i/2]+1;
    }
    int queryMn(int l,int r){ 
        if(l>r)swap(l,r);
        l++;
        int k=Log[r-l+1];
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
    }
    void init(){ 
        scanf("%d%d",&n,&q);
        scanf("%s",str+1); 
        for(int i=1;i<=n;i++) s[i]=str[i];
	    s[++n]=1; //小于所有字符集
        SAIS(s,t,tmp,n,'z'+1); //最大字符集+1
        MakeSA();
        getHt();
        RMQ();
        for(int i=1;i<=n;++i)update(rt[i-1],rt[i],1,n,sa[i]);
    }
    bool check(int x){ 
        int ps=rk[c1];
        int l1=1,r1=ps;
        while(l1<r1){ 
            int mid=l1+r1>>1;
            if(queryMn(mid,ps)>=x)
                r1=mid;
            else l1=mid+1;
        }
        int l2=ps,r2=n;
        while(l2<r2){ 
            int mid=(l2+r2+1)>>1;
            if(queryMn(ps,mid)>=x)
                l2=mid;
            else r2=mid-1;
        }
        int L=r1,R=l2;
        return query(rt[max(0,L-1)],rt[R],1,n,a,b-x+1)>0;
    }
    void solve(){ 
        for(int i=1;i<=q;++i){ 
            scanf("%d%d%d%d",&a,&b,&c1,&d);
            int l=0,r=min(b-a+1,d-c1+1);
            while(l<r){ 
                int mid=(l+r+1)>>1;
                if(check(mid))l=mid;
                else r=mid-1;
            }        
            cout<<l<<"\n";
        }    
    }
}sa;
int main(){
    sa.init();
    sa.solve();
}

