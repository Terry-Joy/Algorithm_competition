#include<bits/stdc++.h>

using namespace std;
int n,m;
const int mod=1000;
struct Matrix{
    int mat[22][22];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(Matrix const &b)const{
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j])%mod;
        return res;
    }
};
Matrix mypow(Matrix a,int b){ 
    Matrix res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=1;i<=n;++i)
        res.mat[i][i]=1;
    while(b){ 
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    while(~scanf("%d%d",&n,&m)&&(n|m)){ 
        Matrix x;
        for(int i=1;i<=m;++i){ 
            int a,b;
            scanf("%d%d",&a,&b);
            x.mat[a+1][b+1]=1;
        }
        int t;
        scanf("%d",&t);
        while(t--){ 
            Matrix A;
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            A=mypow(x,k);
            cout<<A.mat[u+1][v+1]<<endl;
        }
    }
    return 0;
}
