#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
ll jie[14],pot[14],num[10];
int main()
{ 
    int n;
    jie[1]=jie[0]=1;
    for(int i=2;i<=12;++i)
        jie[i]=jie[i-1]*i;
    pot[0]=1;
    for(int i=1;i<=12;++i)
        pot[i]=pot[i-1]*10; 
    while(scanf("%d",&n)==1&&n)
    { 
        ll sum=0;
        int a;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a);
            sum+=a;
            num[a]++;
        }    
        sum=sum*jie[n-1];
        for(int i=0;i<10;++i)
            sum/=jie[num[i]];
        ll ans=0;
        for(int i=0;i<=n-1;++i)
            ans+=pot[i];
        sum*=ans;
        printf("%lld\n",sum);
    }
    return 0;
}
