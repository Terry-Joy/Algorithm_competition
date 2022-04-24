
//KM模板 
//本题hdu6346 用于求二分图最小权匹配 
//如果边权不取反 再对答案取反 用于求二分图最大权匹配
//否则边权取反之后再对答案取反 用于求二分图最小权匹配 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=205;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int t,n;
struct KM{
	int n,m[N],way[N];
	ll w[N][N],lx[N],ly[N],sl[N];
	bool u[N];
	void init(){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				scanf("%lld",&w[i][j]);
				w[i][j]=-w[i][j];
			}
		}
	}
	void hungary(int x){
		m[0]=x;
		int j0=0;
		fill(sl,sl+n+1,INF);
		fill(u,u+n+1,0);
		do{
			u[j0]=1;
			int i0=m[j0],j1=0;
			ll d=INF;
			for(int j=1;j<=n;++j)
			if(u[j]==0){
				ll cur=-w[i0][j]-lx[i0]-ly[j];
				if(cur<sl[j]){sl[j]=cur;way[j]=j0;}
				if(sl[j]<d){d=sl[j];j1=j;}
			}
			for(int j=0;j<=n;++j){
				if(u[j]){lx[m[j]]+=d;ly[j]-=d;}
				else sl[j]-=d;
			}
			j0=j1;
		}while(m[j0]!=0);
		do{
			int j1=way[j0];m[j0]=m[j1];j0=j1;
		}while(j0);
	}
	ll solve(){
		for(int i=1;i<=n;++i)m[i]=lx[i]=ly[i]=way[i]=0;
		for(int i=1;i<=n;++i)hungary(i);
		ll sum=0;
		for(int i=1;i<=n;++i)sum+=w[m[i]][i];
		return sum;
	}
}q;
int main()
{
	scanf("%d",&t);
	for(int c=1;c<=t;++c){
		q.init();
		printf("Case #%d: %lld\n",c,-q.solve());
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=207,NPOS=-1;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct Matrix
{
    int n;
    ll a[N][N];
};
struct KuhnMunkres:Matrix
{
    ll hl[N],hr[N],slk[N];
    int fl[N],fr[N],vl[N],vr[N],pre[N],q[N],ql,qr;
    int check(int i)
    {
        if(vl[i]=1,fl[i]!=NPOS)return vr[q[qr++]=fl[i]]=1;
        while(i!=NPOS)swap(i,fr[fl[i]=pre[i]]);
        return 0;
    }
    void bfs(int s)
    {
        fill(slk,slk+n,INF);
        fill(vl,vl+n,0);
        fill(vr,vr+n,0);
        q[ql=0]=s;
        vr[s]=qr=1;
        for(ll d;;)
        {
            for(; ql<qr; ++ql)
                for(int i=0,j=q[ql]; i<n; ++i)
                    if(d=hl[i]+hr[j]-a[i][j],!vl[i]&&slk[i]>=d)
                        if(pre[i]=j,d)slk[i]=d;
                        else if(!check(i))return;
            d=INF;
            for(int i=0; i<n; ++i)
                if(!vl[i]&&d>slk[i])d=slk[i];
            for(int i=0; i<n; ++i)
            {
                if(vl[i])hl[i]+=d;
                else slk[i]-=d;
                if(vr[i])hr[i]-=d;
            }
            for(int i=0; i<n; ++i)
                if(!vl[i]&&!slk[i]&&!check(i))return;
        }
    }
    void ask()
    {
        fill(pre,pre+n,NPOS);
        fill(fl,fl+n,NPOS);
        fill(fr,fr+n,NPOS);
        fill(hr,hr+n,0);
        for(int i=0; i<n; ++i)hl[i]=*max_element(a[i],a[i]+n);
        for(int j=0; j<n; ++j)bfs(j);
    }
} km;
int main()
{
    int n,nl,nr;
    int QAQ,kase=0;
    scanf("%d",&QAQ);
    while(QAQ--)
    {
        scanf("%d",&n);
        nl=n,nr=n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&km.a[i][j]);
                km.a[i][j]=-km.a[i][j];
            }
        }
        km.n=max(nl,nr);
        km.ask();
        long long ans=0;
        for(int i=0; i<nl; ++i)
            if(km.fl[i]!=NPOS)
                ans+=km.a[i][km.fl[i]];
        printf("Case #%d: %lld\n",++kase,-ans);
    }
}
