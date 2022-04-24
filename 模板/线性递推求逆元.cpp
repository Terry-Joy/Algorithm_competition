//exgcd求逆元 a*b同余1(mod p)
//o(logb) 有逆元即可求 个数不多 mod很大的时候
ll exgcd(ll a,ll b,ll &x,ll &y){ 
    if(!b){ x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll getInv(int a,int mod){ 
    ll x,y;
    ll d=exgcd(a,mod,x,y);
    return d==1?(x%mod+mod)%mod:-1;//最小正整数
}

//费马小定理 O(log mod)
//a、p互质的情况下用 即a^(p-2)
ll mypow(ll a,ll b,ll mod){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return a;
}
ll getInv(int a,ll mod){ return mypow(a,mod-2,mod);}
	
//线性递推求逆元 用于求多个数模m的逆元o（n） 
//调用前预处理 调用时候对除数取模 适用 lucas
ll inv[mod+5];
void init(){ 
    inv[1]=1;
    for(int i=2;i<mod;++i)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}

//线性递推求阶乘逆元
void init(){
    fac[1]=fac[0]=1;
    for(int i=2;i<maxn;++i)fac[i]=1ll*fac[i-1]*i%mod;
    facinv[maxn]=mypow(fac[maxn],mod-2);
    for(int i=maxn-1;i>=0;--i)
        facinv[i]=(1ll*facinv[i+1]*(i+1))%mod;
}
//递归求逆元
ll inv(ll i){ //i和mod互质 i<mod 
    if(i==1)return 1;
    return (mod-mod/i)*inv(mod%i)%mod;
}
