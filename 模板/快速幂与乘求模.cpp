//typedef long long ll;
//typedef long double ld;
ll mypow(ll a,ll b,ll c){
 	ll ans=1%p;
 	while(b){
 		if(b&1)ans=ans*a%c;
 		a=a*a%c;b>>=1;
 }	
 return ans;
} 

//64位整数乘法 a*b%p 10^18   o(log b)
ll mul(ll a,ll b,ll p){
	ll ans=0;
	while(b){
		if(b&1)ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
} 

//O(1)快速乘
ll mul(ll a,ll b,ll p){
    if(p<=1000000000)return a*b%p;//若a*b超了ll，要先%p
    else if(p<=1000000000000ll)return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;//小于1e12的情况下加法分配律 O(1)
    else { //ld类型的快速乘 O(1) p特别大的时候不要用
        ll d=(ll)floor(a*(ld)b/p+0.5);
        ll ret=(a*b-d*p)%p;
        if(ret<0)ret+=p;
        return ret;
    }
}
