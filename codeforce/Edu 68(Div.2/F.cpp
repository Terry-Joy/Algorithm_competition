#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<string>
#define ll long long 
const int maxn=2e5+10,MOD=1e9+7;
using namespace std;
int n,T,inv[maxn],k1[maxn],k2[maxn],ti[maxn],ans,sum;
int n1,k1;
void Init(){
	inv[1]=1;
	for(int i=2;i<maxn;i++){
		inv[i]=((MOD-(MOD/i))*inv[MOD%i]%MOD)%MOD;
	}
	k2[0]=1;
	for(int i=1;i<maxn;i++){
		k2[i]=k2[i-1]*inv[i]%MOD;
	}
	k1[0]=1;
	for(int i=1;i<maxn;i++){
		k1[i]=k1[i-1]*i%MOD;
	}
}
int Quick(int x,int y){
	int res=1,a=x;
	while(y){
		if(y&1)res*=a,res%=MOD;
		a=a*a,a%=MOD;
		y/=2;
	}
	return res;
}
int C(int x,int y){
	if(y==0)return 1;
	if(x==y)return 1;
	return (k1[x]*k2[y])%MOD*k2[x-y]%MOD;
}
int work(int N,int K){
	if(n1==0){
		n1=1;
		for(int i=1;i<=K;i++)n1+=C(N,i),n1%=MOD;
		k1=K;
		return n1; 
	}
	else {
		n1=(n1*2-C(N-1,k1)+MOD)%MOD;
		for(int i=k1;i>=K+1;i--){
			n1-=C(N,i),n1=(n1+MOD)%MOD;
		}
		k1=K;
		return n1;
	}
}
int main(){
	scanf("%lld %lld",&n,&T);
	Init();
	for(int i=1;i<=n;i++)scanf("%lld",&ti[i]);
	int b2=1;
	for(int i=1;i<=n;i++){
		sum+=ti[i];
		b2=b2*2;
		b2%=MOD;
		if(T-sum>=i){
			ans++;
			ans%=MOD;
		}
		else if(T-sum<0){
			break;
		}
		else {
			ans+=(work(i,T-sum)*Quick(b2,MOD-2))%MOD;
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
}
