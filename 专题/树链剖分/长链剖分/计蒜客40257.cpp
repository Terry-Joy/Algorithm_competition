#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=5e5+5,M=1e5+5;
int prime[M+5],md[maxn],hson[maxn],n,T,d,col[maxn],mu[M+5],a[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot;
bool v[M+5];
int cnt,num=0; 
vector<int>fac[M+5],p[M+5];
int *dp[maxn],tmp[maxn],*id=tmp;
ll ans;
void add(int x,int y){
	ver[++tot]=y;next1[tot]=head[x],head[x]=tot;
}
void init(){
	mu[1]=1;
	for(int i=2;i<M;++i){
		if(!v[i])prime[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&prime[j]*i<M;++j){
			v[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=M;++i){
		for(int j=1;j<=M/i;++j){
			if(mu[i])
				fac[i*j].pb(i);
		}
	}
}
void dfs(int x,int f,int val){
	num++;
	md[x]=hson[x]=0;
	for(int i=head[x];i;i=next1[i]){
		int y=ver[i];
		if(y==f||a[y]%val)continue;
		dfs(y,x,val);
		if(!hson[x]||md[y]>md[hson[x]])hson[x]=y;
	}
	md[x]=md[hson[x]]+1;
}
inline int read(){
	char c=getchar();int x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x;
}
inline void in(int&x){
	x=read();
}
void dfs1(int x,int f,int val,int op){
	col[x]=val;
	dp[x][0]=1;
	if(hson[x]&&a[hson[x]]%val==0){
		dp[hson[x]]=dp[x]+1;dfs1(hson[x],x,val,op);
	}
	if(md[x]>d)
		ans+=dp[x][d]*op;
	for(int i=head[x];i;i=next1[i]){
		int y=ver[i];
		if(y==f||y==hson[x]||a[y]%val)continue;
		dp[y]=id;id+=md[y];
		dfs1(y,x,val,op);
		for(int j=0;j<md[y]&&j<d;++j){
			if(d-j-1<md[x])
			ans+=1ll*dp[y][j]*dp[x][d-j-1]*op;
		}
		for(int j=0;j<md[y]&&j<d;++j)
			dp[x][j+1]+=dp[y][j];
	}
}
int main()
{
	init();
	int t=0;
	in(T);
	while(T--){
		in(n);in(d);
		ans=0;
		for(int i=1;i<=n;++i)in(a[i]);
		int u,v;
		for(int i=1;i<n;++i){
			in(u);in(v);
			add(u,v);add(v,u);
		}
		for(int i=1;i<=n;++i){
			for(auto&v:fac[a[i]])
				p[v].pb(i);
		}
		for(int i=2;i<=M;++i){
			if(p[i].empty())continue;
			for(auto rt:p[i]){
				if(col[rt]==i)continue;
				num=0;
				dfs(rt,0,i);
				for(int j=0;j<=num;++j)tmp[j]=0;
				id=tmp;
				dp[rt]=id;id+=md[rt];dfs1(rt,0,i,-mu[i]);
			}
		}
		for(int i=1;i<=M;++i)p[i].clear();
		for(int i=1;i<=n;++i)col[i]=head[i]=0;
		tot=0;
		printf("Case #%d: %lld\n",++t,2*ans);
	}
	return 0;
}