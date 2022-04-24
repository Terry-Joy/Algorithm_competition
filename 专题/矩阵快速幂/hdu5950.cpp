#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=2147493647;
struct Matrix{
    ll mat[10][10];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(const Matrix&b){
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=1;i<=7;++i)
            for(int j=1;j<=7;++j)
                for(int k=1;k<=7;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j])%mod;
        return res;
    }
};
Matrix mypow(Matrix a,int b){
    Matrix res;
    for(int i=1;i<=7;++i)
        res.mat[i][i]=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        Matrix res;
        res.mat[1][1]=1;res.mat[1][2]=2;res.mat[1][3]=1;res.mat[1][4]=4;res.mat[1][5]=6;res.mat[1][6]=4;res.mat[1][7]=1;
        res.mat[2][1]=1;
        res.mat[3][3]=1;res.mat[3][4]=4;res.mat[3][5]=6;res.mat[3][6]=4;res.mat[3][7]=1;
        res.mat[4][4]=1;res.mat[4][5]=3;res.mat[4][6]=3;res.mat[4][7]=1;
        res.mat[5][5]=1;res.mat[5][6]=2;res.mat[5][7]=1;
        res.mat[6][6]=res.mat[6][7]=res.mat[7][7]=1;
        res=mypow(res,n-2);
        cout<<(1ll*res.mat[1][1]*b%mod+res.mat[1][2]*a%mod+res.mat[1][3]*16%mod+res.mat[1][4]*8%mod+res.mat[1][5]*4%mod+res.mat[1][6]*2%mod+res.mat[1][7])%mod<<"\n";
    }
    return 0;
}