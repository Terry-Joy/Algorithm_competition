#include<bits/stdc++.h>
using namespace std;
int tot=0,n,cnt,head[200010];
int maxx=200010,a[200010],vis[300010],f[200010][10],y[200010][10],ans,p[200010];
//p是质数家族 ，y[i][j]是指a[i]的第j大的质因子 
struct abc{
	int to,nxt;
}e[800010];
void add(int u,int v){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void make_zhi(){//求质数的欧拉筛，不懂自行百度（相信各位大佬定会的） 
	for(int i=2;i<=maxx;i++){
		if(!vis[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=maxx;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	//cout<<p[10]<<endl;
}
void dfs(int u,int fa){
    for(int i=1;i<=y[u][0];++i)
        f[u][i]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(fa==v)continue;
		dfs(v,u);
		for(int j=1;j<=y[u][0];j++){
			for(int k=1;k<=y[v][0];k++){
				if(y[u][j]==y[v][k]){
					ans=max(ans,f[u][j]+f[v][k]);
					f[u][j]=max(f[u][j],f[v][k]+1);
				}
			}
		}
	}
}
int main(){
	make_zhi();
	int ff=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ff=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	if(ff){//特判全1时 
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;p[j]*p[j]<=a[i];j++){
			if(a[i]==1)break;
			if(a[i]%p[j]==0){
				y[i][++y[i][0]]=p[j];//太懒于是用y[i][0]存质数个数 
				while(a[i]%p[j]==0)a[i]/=p[j];//统统除掉 
			}
		}
		if(a[i]!=1)y[i][++y[i][0]]=a[i];//剩下了他自己怎么办？靠他了 
	}
	dfs(1,0);
	cout<<ans;
} 
