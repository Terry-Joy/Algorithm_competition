#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e7;
vector<int>factor[10000000];
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a; 
}
int main()
{
    int t;
    scanf("%d",&t);
    int a,b;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(b%a!=0)
            puts("NO SOLUTION");
        else
        { 
            int t=b/a;
            for(int i=t;;i+=t)
            {
                if(t==i/gcd(a,i))
                { 
                        printf("%d\n",i);break;
                } 
            }    
        } 
    }                
    return 0; 
}
