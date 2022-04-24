#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int t,n,m,lines[19][19],lowbits[1<<19],dp[1<<19];
double x[19],y[19];
void equation(double &a,double &b,int i,int j){
	a=(y[i]*x[j]-y[j]*x[i])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
	b=(y[i]*x[j]*x[j]-y[j]*x[i]*x[i])/(x[i]*x[j]*x[j]-x[j]*x[i]*x[i]);
}
int main(){
	int f=(1<<18);
	for(int i=0;i<f;i++){
		int j=1;
		for(;j<=18 && (i&(1<<(j-1)));j++);
		lowbits[i]=j;
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		memset(lines,0,sizeof(lines));
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(fabs(x[i]-x[j])<eps) continue;
				double a,b;
				equation(a,b,i,j);
				if(a>eps)continue;
				for(int k=1;k<=n;k++)
					if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<eps)
						lines[i][j]|=(1<<(k-1));
			}
			int f=(1<<n);
		for(int i=0;i<f;i++){
			int j=lowbits[i];
			dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1); 
			for(int k=1;k<=n;k++)
				dp[i|lines[j][k]]=min(dp[i|lines[j][k]],dp[i]+1); 
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}
