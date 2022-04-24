//杨辉三角
int c[maxn][maxn];
void init(){ 
    c[0][0]=1;
    for(int i=1;i<=n;++i){ 
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}
//预处理逆元
void init(){ 
    fac[1]=fac[0]=1;
    for(int i=2;i<maxn;++i)fac[i]=(ll)fac[i-1]*i%mod;
    facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i)
        facinv[i]=(ll)facinv[i+1]*(i+1)%mod;
}
ll C(int n,int m){ 
    if(n<m)return 0;
    if(m==0||n==m)return 1;
    return (ll)fac[n]*facinv[n-m]%mod*facinv[m]%mod;
}
