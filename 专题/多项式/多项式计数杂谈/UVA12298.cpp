#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e4+5;
const ll mod=4179340454199820289ll;
const ll G=3;
int a,b,c,prime[maxn],cnt,lim;
bool v[maxn];
ll S[maxn<<3],H[maxn<<3],C[maxn<<3],D[maxn<<3],pre[maxn<<3];
ll rev[maxn<<3];
ll mul(ll x,ll y){
	return __int128(x)*y%mod;
}
ll mypow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
ll inv(ll x){
	return mypow(x,mod-2);
}
void init(int N){
	for(int i=2;i<=N;++i){
		if(!v[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=N;++j){
			v[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void getlim(int x){
	lim=1;
	while(lim<x)lim<<=1;
}
void initrev(){
	for(int i=0;i<lim;++i){
		rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
	}
}
void initpre(){
	for(int i=1;i<lim;i<<=1){
		ll w=mypow(G,(mod-1)/(i<<1));
		pre[i]=1;
		for(int j=1;j<i;++j)pre[i+j]=mul(pre[i+j-1],w);
	}
}
void ntt(ll*a,bool tp){
	for(int i=0;i<lim;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int mid=1,cnt=0;mid<lim;mid<<=1,cnt++)
		for(int j=0,len=mid<<1;j<lim;j+=len)
			for(int k=0;k<mid;++k){
				ll x=a[j+k],y=mul(pre[mid+k],a[j+k+mid]);
				a[j+k]=(x+y)%mod;
				a[j+k+mid]=(x-y+mod)%mod;
			}
	if(tp)return;
	ll invlim=inv(lim);
	for(int i=0;i<lim;++i)a[i]=mul(a[i],invlim);
	reverse(a+1,a+lim);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(maxn-4);
	while(cin>>a>>b>>c){
		if(!a&&!b&&!c)break;
		for(int i=0;i<=b;++i)//从0开始
			S[i]=H[i]=C[i]=D[i]=(v[i]==1);
		int x;char s[2];
		for(int i=1;i<=c;++i){
			cin>>x>>s[0];
			if(s[0]=='S')S[x]=0;
			else if(s[0]=='H')H[x]=0;
			else if(s[0]=='C')C[x]=0;
			else if(s[0]=='D')D[x]=0;
		}
		getlim(4*b+5);//最后的总次项
		for(int i=b+1;i<lim;++i)S[i]=H[i]=C[i]=D[i]=0;
		initpre();
		initrev();
		ntt(S,1);ntt(H,1);ntt(C,1);ntt(D,1);
		for(int i=0;i<lim;++i)S[i]=mul(mul(S[i],H[i]),mul(C[i],D[i]));
		ntt(S,0);
		for(int i=a;i<=b;++i)
			cout<<S[i]<<"\n";
		cout<<"\n";
		for(int i=0;i<lim;++i)S[i]=H[i]=C[i]=D[i]=0;
	}
	return 0;
}