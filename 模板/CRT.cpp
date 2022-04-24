//CRT，用于求解x同余多个ai(mod mi)  mi互质
//M=m1*m2..mn Mi=M/mi Miti同余1(mod mi)
//则可以构造x=∑(aiMiti)
//任意解为 x+kM 下面给出的是求最小正整数解 (x+kM)%M、
ll n,m[maxn],a[maxn],M,Mi[maxn];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1,y=0;return;}
    exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-y*(a/b);
}
ll CRT(){
    ll M=1,d,ans=0;
    for(int i=1;i<=n;++i)M*=m[i];
    for(int i=1;i<=n;++i){
        ll x=0,y=0;
        Mi[i]=M/m[i];
        exgcd(Mi[i],m[i],x,y);
        ans=(ans+a[i]*Mi[i]*x)%M;
    }
    return (ans+M)%M;
}
