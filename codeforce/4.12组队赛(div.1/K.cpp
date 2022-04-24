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
    int x,a,b;
    scanf("%d",&x);
    x=x*60;
    scanf("%d%d",&a,&b);
    if(a<=b)
        cout<<(x-a)/b<<endl;
    else
        cout<<(x-b)/a<<endl;
    return 0;
}
