#include<bits/stdc++.h>

using namespace std;
const int maxn=2510;
const int MOD=1e9+7;
typedef long long ll;

int n,k,f[maxn],ans,fac[maxn],inv[maxn];

 int mypow(int a,int b){
	int ans=1;
    while(b)
    { 
		if(b&1) ans=(ll)ans*a%MOD;
		a=(ll)a*a%MOD;
        b>>=1;
	}
	return ans;
}

int C(int x,int y){
	return (ll)fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}

void init()
{
 	int x;fac[0]=1;
	for(int i=1;i<n;i++) 
        scanf("%d",&x);
	for(int i=1;i<=k;i++) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[k]=mypow(fac[k],MOD-2);
	for(int i=k-1;~i;i--) inv[i]=(ll)inv[i+1]*(i+1)%MOD;
}
int main(){
    scanf("%d%d",&n,&k);
    init();
	for(int i=2;i<=k;i++) f[i]=(ll)mypow(i-1,n-1)*i%MOD;
	for(int i=1;i<=k;i++){
		if(!((k-i)&1)) ans=ans+(ll)C(k,i)*f[i]%MOD;
		else ans=ans+(MOD-(ll)C(k,i)*f[i]%MOD);
		ans%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}
