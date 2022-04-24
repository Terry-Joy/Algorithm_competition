//m阶递推式子的转移矩阵一般是m*m 
//复杂度O(m^3 logn)
struct Matrix{ 
    int mat[maxn][maxn];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(Matrix const &b)const{ 
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=1;i<maxn;++i)
            for(int j=1;j<maxn;++j)
                for(int k=1;k<maxn;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j])%mod;
        return res;
    }
}
Matrix mypow(Matrix a,int b){ 
    Matrix res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=1;i<maxn;++i)
        res.mat[i][i]=1;
    while(b){ 
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
