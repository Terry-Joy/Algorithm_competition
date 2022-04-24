#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50,M=5e3+10;
int f[N][M],g[N],id[N],sum[N],cnt[N][M],hav[N][M],ans[N];
int cmp(const int &a,const int &b){return g[a]>g[b];}
void print(int n,int m)
{
	if(!n)return;
	print(cnt[n][m],hav[n][m]);
	if(cnt[n][m]==n)for(int i=1;i<=n;i++)ans[id[i]]++;
	else for(int i=cnt[n][m]+1;i<=n;i++)ans[id[i]]=1;
}
int main()
{
    int n,m;
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&g[i]),id[i]=i;
    sort(id+1,id+n+1,cmp);
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
	    sum[i]=sum[i-1]+g[id[i]];
		for(int j=i;j<=m;j++)
	    {
	    	f[i][j]=f[i][j-i];cnt[i][j]=i;hav[i][j]=j-i;
	    	for(int k=0;k<i;k++)
	    	    if(f[i][j]>f[k][j-(i-k)]+(sum[i]-sum[k])*k)
	    	    {
	    	    	f[i][j]=f[k][j-(i-k)]+(sum[i]-sum[k])*k;
	    	    	cnt[i][j]=k;hav[i][j]=j-(i-k);
				}
		}
	}
	printf("%d\n",f[n][m]);
	print(n,m);
	for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}


