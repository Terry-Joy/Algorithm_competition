#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
struct SA{ 
    int s[(maxn<<1)+5],sa[maxn+5],rk[maxn+5],c[maxn+5],p[maxn+5],tmp[maxn+5],n,m,ht[maxn];
    int L[maxn],R[maxn],q[maxn],h1,t1,a[maxn],mn[maxn][21],mx[maxn][21],Log[maxn];
    char str[maxn+5]; bool t[(maxn<<1)+5];
    ll ans1[maxn],ans2[maxn];
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
        for(int i=1;i<=n;++i)mn[i][0]=mx[i][0]=a[sa[i]];
        for(int j=1;(1<<j)<=n;++j)
            for(int i=1;i+(1<<j)-1<=n;++i){ 
                mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
                mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            }
        Log[1]=0;
        for(int i=2;i<=n+1;++i)
            Log[i]=Log[i/2]+1;
    }
    int queryMx(int l,int r){ 
        int k=Log[r-l+1];
        return max(mx[l][k],mx[r-(1<<k)+1][k]);
    }
    int queryMn(int l,int r){ 
        int k=Log[r-l+1];
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
    }
    inline int read(){ 
        char c=getchar();int x=0,s=1;
        while(c<'0'||c>'9'){ if(c=='-')s=-1;c=getchar();}
        while(c>='0'&&c<='9'){ x=x*10+c-'0';c=getchar();}
        return x*s;
    }
    void init(){ 
        scanf("%d",&n);
        scanf("%s",str+1);
        for(int i=1;i<=n;++i)a[i]=read();
        for(int i=1;i<=n;i++) s[i]=str[i];
	    s[++n]=1; //小于所有字符集
        SAIS(s,t,tmp,n,'z'+1); //最大字符集+1
        MakeSA();
        getHt();
        RMQ();
    }
    void solve(){ 
        h1=1;t1=0;
        for(int i=1;i<=n;++i){ 
            while(h1<=t1&&ht[q[t1]]>=ht[i])
                R[q[t1--]]=i;
            L[i]=max(1,q[t1]);
            q[++t1]=i;
        }
        while(h1<=t1)R[q[t1--]]=n+1;
        for(int i=1;i<=n;++i)ans2[i]=-9e18;
        for(int i=2;i<=n;++i){ 
            ll del=(ll)(i-L[i])*(R[i]-i);
            ans1[0]+=del;ans1[ht[i]+1]-=del;
            int mnL=queryMn(L[i],i-1),mnR=queryMn(i,R[i]-1);
            int mxL=queryMx(L[i],i-1),mxR=queryMx(i,R[i]-1);
            ans2[ht[i]]=max(ans2[ht[i]],max((ll)mnL*mnR,(ll)mxL*mxR));
        }
        for(int i=1;i<=n-1;++i)
            ans1[i]+=ans1[i-1];
        for(int i=n-2;i>=0;--i)
            ans2[i]=max(ans2[i],ans2[i+1]);
        for(int i=0;i<=n-1;++i)
            cout<<ans1[i]<<" "<<(ans1[i]?ans2[i]:0)<<"\n";
    }
}sa;
int main(){
    sa.init();
    sa.solve();
}
