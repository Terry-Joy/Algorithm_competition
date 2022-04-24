#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=2147493647;
struct Matrix{ 
    ll mat[9][9];
    Matrix(){ memset(mat,0,sizeof(mat));}
    Matrix operator*(Matrix const&b)const{ 
        Matrix res;
        for(int i=1;i<=7;++i)
            for(int j=1;j<=7;++j)
                for(int k=1;k<=7;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j]%mod)%mod;
        return res;
    }
};
Matrix mypow(Matrix a,int b){ 
    Matrix res;
    for(int i=1;i<=7;++i)res.mat[i][i]=1;
    while(b){ 
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t;
    cin>>t;
    int n,a,b;
    while(t--){ 
        cin>>n>>a>>b;
        if(n==1){ cout<<a%mod;continue;}
        if(n==2){ cout<<b%mod;continue;}
        Matrix Base,T;
        T.mat[1][1]=1;T.mat[1][2]=2;T.mat[1][3]=1;T.mat[1][4]=4;T.mat[1][5]=6;T.mat[1][6]=4;T.mat[1][7]=1;
        T.mat[2][1]=1;
        T.mat[3][3]=1;T.mat[3][4]=4;T.mat[3][5]=6;T.mat[3][6]=4;T.mat[3][7]=1;
        T.mat[4][4]=T.mat[4][7]=1;T.mat[4][5]=T.mat[4][6]=3;
        T.mat[5][5]=T.mat[5][7]=1;T.mat[5][6]=2;
        T.mat[6][6]=T.mat[6][7]=T.mat[7][7]=1;
        Base.mat[1][1]=b;Base.mat[2][1]=a;
        Base.mat[3][1]=16;Base.mat[4][1]=8;Base.mat[5][1]=4;Base.mat[6][1]=2;Base.mat[7][1]=1;
        T=mypow(T,n-2);
        T=T*Base;
        cout<<T.mat[1][1]<<"\n";
    }
    return 0;
}

