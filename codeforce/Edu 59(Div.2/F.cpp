#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int t,n;
struct KM{
	int n,m[N],way[N];
	ll w[N][N],lx[N],ly[N],sl[N];
	bool u[N];
	void init(){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
            int a,b,k;
            scanf("%d%d%d",&a,&b,&k);
			for(int j=1;j<=n;++j){
                w[i][j]=max(a-1ll*b*min(k,j-1),0ll);
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
		q.init();
        printf("%lld\n",q.solve());
	return 0;
}
