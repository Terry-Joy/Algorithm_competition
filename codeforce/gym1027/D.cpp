#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,k,m;
const ll mod=1e9+7;
struct Matrix{ 
    ll mat[210][210];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(Matrix const&b)const{ 
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j)
                for(int k=0;k<m;++k)
                    res.mat[i][j]=(res.mat[i][j]+this->mat[i][k]*b.mat[k][j]%mod)%mod;
        return res;
    }
};
int res[210];
Matrix mypow(Matrix a,int b){ 
    Matrix res;
    for(int i=0;i<m;++i)
        res.mat[i][i]=1;
    while(b){ 
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
ll pow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<m;++i)
        res[i]=k/m;
    ll tmp=pow(k-k/m,n);
    tmp=pow(tmp,mod-2);
    k%=m;
    for(int i=1;i<=k;++i)res[i]++;
    res[0]=0;
    Matrix m1,Base;
    for(int i=0;i<m;++i)
        Base.mat[i][0]=res[i];
    for(int i=0;i<m;++i){ 
        int pos=0;
        for(int j=i;j>=0;--j)m1.mat[i][pos++]=res[j];
        for(int j=m-1;;--j){ 
            if(pos==m)break;
            m1.mat[i][pos++]=res[j];
        }
    }
    m1=mypow(m1,n);
    cout<<m1.mat[0][0]*tmp%mod;
    return 0;
}
