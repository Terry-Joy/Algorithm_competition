#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=10007;
struct Matrix{
    int mat[4][4];
    Matrix(){}
    Matrix operator*(Matrix const &b)const{
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=1;i<=3;++i)
            for(int j=1;j<=3;++j)
                for(int k=1;k<=3;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j])%mod;
        return res;
    }
};
Matrix mypow(Matrix a,int b){
    Matrix res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=1;i<=3;++i)
        res.mat[i][i]=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==1){puts("2");continue;}
        Matrix a;
        a.mat[1][1]=2;a.mat[1][2]=1;a.mat[1][3]=0;
        a.mat[2][1]=2;a.mat[2][2]=2;a.mat[2][3]=2;
        a.mat[3][1]=0;a.mat[3][2]=1;a.mat[3][3]=2;
        a=mypow(a,n-1);
        cout<<(2*a.mat[1][1]+2*a.mat[1][2])%mod<<endl;
    }
    return 0;
}