#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e7+7;
int n,m;
struct Matrix{
    ll mat[14][14];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(const Matrix &b)const{
        Matrix res;
        for(int i=0;i<12;++i)
            for(int j=0;j<12;++j)
                for(int k=0;k<12;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j])%mod;
        return res;
    }
};
Matrix mypow(Matrix a,int b){
    Matrix ans;
    for(int i=0;i<=n+1;++i)ans.mat[i][i]=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        Matrix A,B;
        A.mat[0][0]=23;A.mat[n+1][0]=3;
        for(int i=1;i<=n;++i)scanf("%lld",&A.mat[i][0]);
        for(int i=0;i<=n;++i)B.mat[i][0]=10;
        for(int i=1;i<=n;++i){
            int cnt=1;
            for(int j=1;cnt<=i;j++,cnt++){
                B.mat[i][j]=1;
            }
        }
        for(int i=n+1;i>=0;--i)B.mat[i][n+1]=1;
        B=mypow(B,m);
        B=B*A;
        printf("%d\n",B.mat[n][0]);
    }
    return 0;
}