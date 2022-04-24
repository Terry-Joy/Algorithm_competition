#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e7+7;
const int maxn=1e5+5;
int n,k,a[maxn];
struct  Matrix{
    ll mat[5][5];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(const Matrix&b){
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=1;i<=3;++i)
            for(int j=1;j<=3;++j)
                for(int k=1;k<=3;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j]%mod)%mod;
        return res;              
    }
};
Matrix mypow(Matrix a,int b){
    Matrix ans;
    for(int i=1;i<=3;++i)
        ans.mat[i][i]=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>k){
        ll sum=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            sum+=a[i];
            if(sum>=mod)sum%=mod;
        }
        sort(a+1,a+1+n);
        int a1=a[n-1],b1=a[n];
        Matrix op,init;
        op.mat[1][1]=op.mat[1][2]=op.mat[2][1]=op.mat[3][1]=op.mat[3][3]=1;
        op=mypow(op,k-1);
        init.mat[1][1]=init.mat[2][1]=init.mat[3][1]=1;
        op=op*init;
        cout<<(sum+1ll*op.mat[3][1]*a1%mod+(op.mat[3][1]+op.mat[1][1]-1+mod)%mod*b1%mod)%mod<<"\n";
    }
    return 0;
}