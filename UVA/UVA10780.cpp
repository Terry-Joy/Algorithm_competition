#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
    int t;
    scanf("%d",&t);
    int k=0;
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int ans=INF,i=2;
        while(m!=1)
        { 
            int c1=0;
            while(m%i==0)m/=i,c1++;
            if(c1)
            { 
                int sum=n,c2=0;
                while(sum)
                {
                    c2+=sum/i;
                    sum/=i;
                }
                ans=min(ans,c2/c1);
            }
            ++i;
        }
        printf("Case %d:\n",++k);
        if(!ans)
            puts("Impossible to divide");
        else
            printf("%d\n",ans);
    } 
    return 0;
}
