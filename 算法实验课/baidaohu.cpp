#include<bits/stdc++.h>
using namespace std;
using db=double;
const int maxn=105;
struct Node{
	db x,y;
}a[maxn];
struct Edge{
	int x,y;
	db z;
	bool operator<(const Edge&a)const{
		return z<a.z;
	}
}edge[maxn*maxn+5];
int fa[maxn],cnt;
db dis(int i,int j){return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lf%lf",&a[i].x,&a[i].y);
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(dis(i,j)>=10&&dis(i,j)<=1000)
					edge[++cnt]={i,j,dis(i,j)};
			}
		}
		sort(edge+1,edge+1+cnt);
		int num=0;
		db ans=0;
		for(int i=1;i<=cnt;++i){
			int x=edge[i].x,y=edge[i].y;
			int xx=find(x),yy=find(y);
			if(xx==yy)continue;
			fa[xx]=yy;
			num++;
			ans+=edge[i].z;
		}
		if(num==n-1){
			printf("%.1f\n",ans*100);
		}else
			puts("no!");
	}
	return 0;
}