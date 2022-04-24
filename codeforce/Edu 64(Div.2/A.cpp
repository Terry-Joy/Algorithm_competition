
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 110;
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    bool flag=1;
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        if(a[i-1]==3)
        {
           if(a[i]==1)ans+=4;
           else flag=0; 
        }
        if(a[i-1]==1)
        {
           if(a[i]==2)ans+=3;
           else if(a[i]==3)ans+=4;
           else flag=0; 
        }
        if(a[i-1]==2)
        {
           if(a[i]==1)ans+=3;
           else flag=0; 
        }
    }
    for(int i=3;i<=n;++i)
        if(a[i-2]==3&&a[i-1]==1&&a[i]==2)
            ans--;
    if(!flag)
        puts("Infinite");
    else
    { 
        puts("Finite");
        cout<<ans;
    }
}
