#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    printf("? ");
    for(int i=1;i<=100;++i)
        printf(" %d",i);
    puts("");
    fflush(stdout);
    int t;
    scanf("%d",&t);
    int ans=0;
    for(int i=7;i<14;++i)
        ans+=((t>>i&1)<<i);
    printf("? ");
    for(int i=1;i<=100;++i)
        printf(" %d",i<<7);
    puts("");
    fflush(stdout);
    scanf("%d",&t);
    for(int i=0;i<7;++i)
        ans+=((t>>i&1)<<i);
    printf("! %d",ans);
    return 0;
}


