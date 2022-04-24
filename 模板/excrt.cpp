//EXCRT求解x同余ai(mod mi) mi不互质
ll mi[maxn],ai[maxn];
ll mul(ll a,ll b){//快速乘防爆ll
    ll ans=0;
    while(b){
        if(b&1)ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1,y=0;return a;}
    ll gcd=exgcd(b,a%b,x,y);
    ll z=x;x=y;y=z-y*(a/b);
    return gcd;
}
ll excrt(){
    ll x,y,k;
    ll M=mi[1],ans=ai[1];//特判只有一个方程的解
    for(int i=2;i<=n;++i){
        ll a=M,b=mi[i],c=((ai[i]-ans)%b+b)%b;//ax同余c(mod b)
        ll gcd=exgcd(a,b,x,y),bg=b/gcd;
        if(c%gcd!=0)return -1;//判断是否有解
        x=mul(x,c/gcd,bg);//exgcd求出x的解
        ans+=x*M;         //加法更新前k个的答案
        M*=bg;             //前k个的lcm
        ans=(ans%M+M)%M;
    }
    return ans;
}