#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
struct Matrix{
    int mat[3][3];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(const Matrix&b)const{
        Matrix res;
        for(int i=1;i<=2;++i)
            for(int j=1;j<=2;++j)
                for(int k=1;k<=2;++k)
                    res.mat[i][j]=(res.mat[i][j]+1ll*mat[i][k]*b.mat[k][j])%mod;
        return res;
    }
}ans,T;
Matrix mypow(Matrix a,ll b){
    Matrix res;
    for(int i=1;i<=2;++i)
        res.mat[i][i]=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    ll n;
    scanf("%lld",&n);
    if(n<=2){
        puts("1");
        return 0;
    }
    T.mat[1][1]=T.mat[1][2]=T.mat[2][1]=1;
    T.mat[2][2]=0;
    ans=mypow(T,n-1);
    printf("%lld\n",ans.mat[1][1]%mod);
}