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
                f[i][j][k]=f[i-1][j][k];//һ������Ҳ���ŵ����
                if(j>=1) f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k]*(m-k-j+1))%mod;//����1�����ӣ����Ҵ����ӷ�����ԭ����0�����ӵ�һ����
                if(k>=1) f[i][j][k]=(f[i][j][k]+f[i-1][j+1][k-1]*(j+1))%mod;//����1�����ӣ����Ҵ����ӷ�����ԭ����1�����ӵ�һ����
                if(j>=2) f[i][j][k]=(f[i][j][k]+f[i-1][j-2][k]*(((m-j-k+1)*(m-j-k+2))/2))%mod;//�����������ӣ������������Ӷ�������ԭ����0�����ӵ�������
                if(j&&k) f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1]*(j*(m-j-k+1)))%mod;//�����������ӣ������������ӷֱ������ԭ����0�����ӵ�һ�к�ԭ����1�����ӵ�һ����
                if(k>=2) f[i][j][k]=(f[i][j][k]+f[i-1][j+2][k-2]*(((j+1)*(j+2))/2))%mod;//�����������ӣ������������Ӷ���ԭ����1�����ӵ�������
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
