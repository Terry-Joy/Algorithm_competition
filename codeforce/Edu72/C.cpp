#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
char s[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        int l=1,ans=0;
        for(int i=1;i<=len;++i)
        {
            if(s[i]=='1')
            {  
                int  rec=0;
                for(int j=i;j<=i+20&&j<=len;++j)
                {
                    rec=rec*2+s[j]-'0';
                    if(rec>j-l+1)
                        break;
                    else
                        ans++; 
                }
                l=i+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0; 
}
