#include<bits/stdc++.h>
#include<random>
using namespace std;
const int maxn=2e5+5;
const int N=2e6+5;
typedef long long ll;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
ll a[maxn];
int prime[N+5];
int tot,m,n;
bool v[N+5];
void init(){
	for(int i=2;i<N;++i){
		if(!v[i])prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<N;++j){
			v[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int solve(ll mod,ll c){
	int sum=0;
	for(int i=1;i<=n;++i)sum+=(a[i]%mod==c);
	return sum;
}
int main(){ 
	mt19937 rand_num(seed);  // 大随机数
	//cout << dist(rand_num) << endl;
    int t;
    init();
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        int ans=(n+1)/2;
        for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	    uniform_int_distribution<int> dist(1, n);  // 给定范围
        int T=40;
        //cout<<pow(0.75,T)<<"\n";
        for(int i=1;i<=T;++i){ 
            tot=m=0;
            int l=dist(rand_num),r=dist(rand_num);
            if(l==r)continue;
            ll x=abs(a[l]-a[r]);
            for(int j=1;(ll)prime[j]*prime[j]<=x;++j){
				if(x%prime[j]==0){
					ans=max(ans,solve(prime[j],a[l]%prime[j]));
					while(x%prime[j]==0)x/=prime[j];
				}
			}
			if(x>1)ans=max(ans,solve(x,a[l]%x));
        }
        cout<<ans<<"\n";
    }
    return 0;
}

