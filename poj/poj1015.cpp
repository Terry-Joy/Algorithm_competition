#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[25][1000],path[25][1000],a[220],b[220],s[220],v[220],id[30];
bool select(int j,int k,int i)
{
	if(j==0)return false;
	if(path[j][k]==i)return true;
	return select(j-1,k-v[path[j][k]],i);
}
int main()
{
	int n,m,cas=1;
	while(~scanf("%d%d",&n,&m)&&(n||m))
	{//dp[i][j]��ʾ�Ѿ�ѡ��i����ʱ��������ֵ�Ĳ�Ϊj��ʱ������ֵ�ĺ����ֵ 
		int tot=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&a[i],&b[i]);
			s[i]=a[i]+b[i];
			v[i]=a[i]-b[i];
		}
		int fix=20*m;
		memset(dp,-1,sizeof(dp));
		dp[0][fix]=0;
		for(int j=1;j<=m;++j){//���j�� 
			for(int k=0;k<=2*fix;++k){	//�Ѳ�[-a,a]ƽ�Ƶ�[0,2a] 
		 		if(dp[j-1][k]>=0){		//ǰһ���׶�Ҫ���� 
		 			for(int i=1;i<=n;++i)
		 			if(dp[j][k+v[i]]<dp[j-1][k]+s[i])//ֵ��ת��
					 	if(select(j-1,k,i))
					 	{
							dp[j][k+v[i]]=dp[j-1][k]+s[i];
							path[j][k+v[i]]=i;
						 } 
						}
				}
			}
			int k;
		for(k=0;k<=fix;++k)
			if(dp[m][fix-k]>=0||dp[m][fix+k]>=0)//���м����������� 
				break;
		int div=dp[m][fix-k]>dp[m][fix+k]?fix-k:fix+k;//��¼��С��ز� 
		printf("Jury #%d\n",cas++);
		int maxn=(dp[m][div]+div-fix)/2;int minn=(dp[m][div]-div+fix)/2;  
		printf("Best jury has value %d for prosecution and value %d for defence:\n",maxn,minn);
		int x=m,y=div;
		while(x)
		{
			id[++tot]=path[x][div];
			div-=v[path[x][y]];
			y--;
		}
		sort(id+1,id+tot+1);
		for(int i = 1; i <= tot; i++)
		printf(" %d",id[i]);
		putchar('\n');
	}
	return 0;
} 
