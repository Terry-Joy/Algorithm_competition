#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 

using namespace std;
const int maxn=50;
int a[maxn],b[maxn],c[maxn],md;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        md=max(md,a[i]); 
    }
    for(int i=0;i<md*1825;++i)
    {
        bool flag=0;
        for(int j=1;j<=n;++j)
        {
            int f=i;
            f%=a[j];
            if(b[j]<=c[j]&&(f<=b[j]||f>=c[j]))
                flag=0;
            else if(b[j]>c[j]&&(f<=b[j]&&f>=c[j]))
                flag=0;
            else 
            { 
                flag=1; 
                break;
            }
        } 
        if(!flag)
        { 
            cout<<i<<"\n";
            return 0;
        }
    }
    puts("impossible");
    return 0; 
}
