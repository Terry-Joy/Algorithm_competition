#include<cstdio>
#include<iostream>
#define maxn 110
#define mod 9999973
using namespace std;
long long  f[maxn][maxn][maxn];
long long n,m;
int main()
    {
    cin>>n>>m;
    f[0][0][0]=1;
    for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
        {
            int MAX_K=m-j;
            for(int k=0;k<=MAX_K;k++)
                {
                f[i][j][k]=f[i-1][j][k];//一个棋子也不放的情况
                if(j>=1) f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k]*(m-k-j+1))%mod;//放置1个棋子，并且此棋子放置在原来有0个棋子的一列上
                if(k>=1) f[i][j][k]=(f[i][j][k]+f[i-1][j+1][k-1]*(j+1))%mod;//放置1个棋子，并且此棋子放置在原来有1个棋子的一列上
                if(j>=2) f[i][j][k]=(f[i][j][k]+f[i-1][j-2][k]*(((m-j-k+1)*(m-j-k+2))/2))%mod;//放置两个棋子，并且两个棋子都放置在原来有0个棋子的两列上
                if(j&&k) f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1]*(j*(m-j-k+1)))%mod;//放置两个棋子，并且两个棋子分别放置在原来有0个棋子的一列和原来有1个棋子的一列上
                if(k>=2) f[i][j][k]=(f[i][j][k]+f[i-1][j+2][k-2]*(((j+1)*(j+2))/2))%mod;//放置两个棋子，并且两个棋子都在原来有1个棋子的两列上
                }
        }   
        }
    long long ans=0;
    for(int i=0;i<=m;i++)
        {
        int max_n=m-i;
        for(int j=0;j<=max_n;j++)
            {
                ans=(ans+f[n][i][j])%mod;
            }
        }
    cout<<ans<<endl;
    return 0;
    }
