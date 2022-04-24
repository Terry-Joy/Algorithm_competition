#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;
int a[10]={4,8,15,16,23,42},d[5];
int main()
{ 
    for(int i=1;i<=4;++i)
    {
       printf("? %d %d\n",i,i+1);
       fflush(stdout);
       scanf("%d",&d[i]); 
    }
    do{ 
        if(a[1]*a[0]==d[1]&&a[2]*a[1]==d[2]&&a[3]*a[2]==d[3]&&a[3]*a[4]==d[4])
            break;
    }while(next_permutation(a,a+6));
    printf("!");
    for(int i=0;i<6;++i)
        printf(" %d",a[i]);
    fflush(stdout);
    return 0;
}
