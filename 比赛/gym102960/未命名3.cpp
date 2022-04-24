#include <bits/stdc++.h>
#define N 102
#define fi first
#define se second 
#define mm make_pair
using namespace std;
typedef long long ll;
int dis[N][1<<10],vis[N][1<<10];
int tot,head[N],id[N],p[N],pp;
int n,m,f,k,ff[N];
queue<pair<int,int> >q;
struct edge{
	int n,to,l;
}e[N*N];
inline void add(int u,int v,int w){
	e[++tot].n=head[u];
	e[tot].to=v;
	e[tot].l=w;
	head[u]=tot;
}
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
inline bool check(int pos){
	memset(dis,-1,sizeof(dis));
	q.push(mm(1,0));
	dis[1][0]=pos;vis[1][0]=1;
	while(!q.empty()){
		int x1=q.front().fi,x2=q.front().se;q.pop();
		vis[x1][x2]=0;
	//	cout<<x1<<" "<<x2<<" "<<dis[x1][x2]<<endl;
		for(int i=head[x1];i;i=e[i].n)if(dis[x1][x2]>=e[i].l){
			int v=e[i].to;
			int ss=id[v]?(1<<id[v]-1):0;
			if(dis[v][x2|ss]<min(f,dis[x1][x2]-e[i].l+ff[v])){
				dis[v][x2|ss]=min(f,dis[x1][x2]-e[i].l+ff[v]);
				if(!vis[v][x2|ss]){
					q.push(mm(v,x2|ss));
					vis[v][x2|ss]=1; 
				}
			}
		}
	}
//	cout<<pos<<" "<<dis[1][(1<<k)-1]<<endl;
	if(dis[1][(1<<k)-1]>=0)return 1;
	else return 0;
}
int main(){
   n=rd();m=rd();k=rd();f=rd();
   for(int i=1;i<=k;++i){
   	  p[i]=rd();
   	  id[p[i]]=i;
   }
   int u,v,w;
   for(int i=1;i<=m;++i){
   	  u=rd();v=rd();w=rd();
	  add(u,v,w);add(v,u,w); 
   }
   pp=rd();
   for(int i=1;i<=pp;++i){
   	u=rd();v=rd();ff[u]=v; 
   }
   int l=1,r=f,ans=-1;
   while(l<=r){
   	int mid=(l+r)>>1;
   	if(check(mid))ans=mid,r=mid-1;
   	else l=mid+1;
   }
   cout<<ans;
   return 0;
}

