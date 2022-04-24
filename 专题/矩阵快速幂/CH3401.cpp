#include <bits/stdc++.h>
using namespace std;
#define maxn 70
#define mod 1000000007
#define ll long long 
int n,m,t,act;
struct Matrix
{
    long long ma[maxn][maxn];
    Matrix() {
        memset(ma,0, sizeof(ma));
    }
}f,e[maxn],d;
Matrix mul(Matrix A,Matrix B)
{
    Matrix C;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                C.ma[i][j] += (A.ma[i][k]*B.ma[k][j]);
    return C;
}
Matrix cel(Matrix A,Matrix B) {
    ll w[70]={0};
    for(int j=0;j<=n*m;j++)
        for(int k=0;k<=n*m;k++)
            w[j]+=A.ma[1][k]*B.ma[k][j];
    memcpy(A.ma[1],w,sizeof(w));
    return A;
}
Matrix pow_mod(Matrix A,long long t)
{
    Matrix B = d;
    while(t) {
        if(t&1) A = cel(A,B);  //可直接mul(f,e[i]);
        B=mul(B,B);
        t>>=1;
    }
    return A;
}
char s[10][10],cz[maxn][10];
int len[maxn];
int num(int i,int j) {return (i-1)*m+j;}
int main()
{
    scanf("%d%d%d%d",&n,&m,&t,&act);
    for (int i = 1; i <= n; i++) scanf("%s",s[i]+1);
    for (int i = 0; i < act; i++) scanf("%s",cz[i]),len[i] = strlen(cz[i]);
    for (int k = 1; k <= 60; k++) {
        e[k].ma[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = s[i][j] - '0', y = (k-1)%len[x];
                if (cz[x][y] >= '0' && cz[x][y] <= '9') {
                    e[k].ma[0][num(i,j)] = cz[x][y]-'0';
                    e[k].ma[num(i,j)][num(i,j)] = 1;
                } else if (cz[x][y] == 'N' && i-1>0) e[k].ma[num(i,j)][num(i-1,j)] = 1;
                else if (cz[x][y] == 'W' && j-1>0) e[k].ma[num(i,j)][num(i,j-1)] = 1;
                else if (cz[x][y] == 'S' && i+1<=n) e[k].ma[num(i,j)][num(i+1,j)] = 1;
                else if (cz[x][y] == 'E' && j+1<=m) e[k].ma[num(i,j)][num(i,j+1)] = 1;
            }
        }
        if (k == 1) d = e[1];
        else d = mul(d,e[k]);
    }
    ll ans = 0;
    f.ma[1][0] = 1;
    f = pow_mod(f,t/60);
    int z = t%60;
    for (int i = 1; i <= z; i++) f = cel(f,e[i]);  //可直接mul(f,e[i]);
    for (int i = 0; i <= n*m; i++) ans = max(ans,f.ma[1][i]);
    printf("%lld\n",ans);
    return 0;
}