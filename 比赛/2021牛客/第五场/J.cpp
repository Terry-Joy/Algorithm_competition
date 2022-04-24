#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=305;
int n,m,mat[maxn],pre[maxn];
ll wisha[maxn],wishb[maxn],slack[maxn],cost[maxn][maxn];
bool va[maxn],vb[maxn];
template<class T,class T2>
void init(T a[],T2 b){ 
	for(int i=0;i<=n;i++)	a[i]=b;
}
void bfs(int u){
	init( pre,0 );
	init( slack,inf ); slack[0]=0;
	int x=0,y=0,yy=0;
    ll delta=0;
	mat[y]=u; 
	while( 1 ){
		x=mat[y], delta=inf, vb[y]=1;
		for(int i=1;i<=n;i++){
			if( vb[i] )	continue;
			if( slack[i]>wisha[x]+wishb[i]-cost[x][i] ){
				slack[i]=wisha[x]+wishb[i]-cost[x][i];
				pre[i]=y;
			}
			if( slack[i]<delta )	delta=slack[i],yy=i;
		}
		for(int i=0;i<=n;i++){
			if( vb[i] )	wisha[mat[i]]-=delta,wishb[i]+=delta;
			else	slack[i]-=delta;
		}
		y=yy;
		if( mat[y]==-1 )	break;
	} 
	while( y )	mat[y]=mat[ pre[y] ],y=pre[y];
}
ll km(){
	init(wisha,0 ); init(wishb,0 ); init(mat,-1 );
	for(int i=1;i<=n;i++){
		init(vb,0 );
		bfs(i);
	}
	ll res=0;
	for(int i=1;i<=n;i++)	res+=cost[mat[i]][i];
	return res;
}
int x[maxn],y[maxn],z[maxn],v[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
    ll ans=0;
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i]>>z[i]>>v[i],ans+=x[i]*x[i]+y[i]*y[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){ 
            cost[i][j]=-(((ll)z[j]+(i-1)*v[j])*(z[j]+(i-1)*v[j]));
        }
	cout << ans-km() << '\n';
}
