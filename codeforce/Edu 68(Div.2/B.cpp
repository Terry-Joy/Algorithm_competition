#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=5e4+5;
//记得要开string的数组，开不了char的二维数组
string str[maxn];
//把行和列分成两个数组，就不会有问题
int h[maxn],l[maxn];//计算每行每列有多少白的
const int inf=0x3f3f3f;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(h,0,sizeof(h));
        memset(l,0,sizeof(l));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        cin>>str[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='.')
                h[i]++;
            }
        }
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(str[i][j]=='.')
                l[j]++;
            }
        }
        int ans=0,minn=inf;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='.')
                ans=-1;
                else
                ans=0;
                if(h[i]+l[j]+ans<minn)
                minn=h[i]+l[j]+ans;

            }
        }
        printf("%d\n",minn);
    }
    return 0;
}
