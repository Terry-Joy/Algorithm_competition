#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,m;
struct Matrix{
    int mat[65][65];
    Matrix(){}
    Matrix operator*(const Matrix&b)const{
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=1;i<=2*n;++i)
            for(int j=1;j<=2*n;++j)
                for(int k=1;k<=2*n;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j])%m;
        return res;
    }
};
Matrix mypow(Matrix a,int b){
    Matrix res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=1;i<=2*n;++i)
        res.mat[i][i]=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    Matrix a;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&a.mat[i][j]);
        }
            a.mat[i][i+n]=1;a.mat[i+n][i+n]=1;
    }
    a=mypow(a,k+1);
    for(int i=1;i<=n;++i){
        for(int j=n+1;j<2*n;++j){
            if(j==i+n)cout<<((a.mat[i][j]-1)%m+m)%m<<" ";
            else cout<<a.mat[i][j]<<" ";
        }
        if(2*n==i+n)cout<<((a.mat[i][2*n]-1)%m+m)%m<<endl;
        else cout<<a.mat[i][2*n]<<endl;
    }
    return 0;
}