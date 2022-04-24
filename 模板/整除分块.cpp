ll G(ll n,ll k)		//∑ i=(1,n) (k/i)*i
{
    ll l=1,r=0,ans=0;
    for(;l<=n&&k/l;l=r+1){ //特判0的地方
        r=min(k/(k/l),n);
        ans=(ans+(k/l)*(l+r)%mod*(r-l+1)%mod*inv2%mod)%mod;
    }
    return ans;
}
