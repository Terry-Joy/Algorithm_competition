#include <bits/stdc++.h>
using namespace std;
const int maxn=10;
const int INF=0x3f3f3f3f;
int dis[maxn][maxn];
int num[maxn][maxn];
const int len=2e6+10;
char s[len];
int length;
void work(int x,int y)
{
    memset(dis,INF,sizeof dis);
    for(int i=0; i<maxn; i++)
        dis[i][(i+x)%10]=dis[i][(i+y)%10]=1;
    for(int k=0; k<maxn; k++)
        for(int i=0; i<maxn; i++)
            for(int j=0; j<maxn; j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1; i<length; i++)
    {
        int a=s[i-1]-'0';
        int b=s[i]-'0';
        if(dis[a][b]==INF)
        {
            num[x][y]=-1;
            return ;
        }
        num[x][y]+=(dis[a][b]-1);
    }
}
int main()
{
    scanf("%s",s);
    length=strlen(s);
    for(int i=0; i<maxn; i++)
        for(int j=0; j<=i; j++)
        {
            work(i,j);
            num[j][i]=num[i][j];
        }
    for(int i=0; i<maxn; i++)
    {
        for(int j=0; j<maxn-1; j++)
            printf("%d ",num[i][j]);
        printf("%d\n",num[i][9]);
    }
    return 0;
}
