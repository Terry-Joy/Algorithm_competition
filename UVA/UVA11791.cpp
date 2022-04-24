#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
int main()
{
    int n,f=0;
    while(~scanf("%d",&n)&&n)
    {
        int k=sqrt(n); 
        ll sum=0,cnt=0;
        for(int i=2;i<=k;++i)
        {
            if(n%i==0)
            { 
                cnt++;
                ll tmp=1;
                while(n%i==0)
                { 
                    tmp*=i;
                    n/=i;
                }  
                sum+=tmp;
            }
        } 
        if(n!=1||cnt==0)
        {
           sum+=n;
           cnt++; 
        }
        if(cnt==1)sum++;
        printf("Case %d: %lld\n",++f,sum);
    }
    return 0; 
}
