#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long

using namespace std;

int main()
{
    ll t,k;
    scanf("%lld%lld",&t,&k);
    printf("%lld",t+1+(t-1)/k);
    return 0;
}
