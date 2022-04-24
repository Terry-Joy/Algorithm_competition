#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
const int maxn=1010;
 using namespace std;
int is[maxn];
int t[maxn],l[maxn],r[maxn];
 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
        l[i]--,r[i]--;
        if(t[i]==1)
        {
            for(int j=l[i];j<r[i];++j)
                is[j]=1;
        }
    }
   for(int i=0;i<m;++i)
    {
        int flag=0;
        if(!t[i])
        {
            for(int j=l[i];j<r[i];++j)
                if(!is[j])
                {
                    flag=1;
                    break;
                }
            if(!flag)
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    int ans=n;
    printf("%d ",ans);
    for(int i=1;i<n;++i)
    {
        if(is[i-1])
            printf("%d ",ans);
        else
            printf("%d ",--ans);
    }
   cout<<endl;
}

