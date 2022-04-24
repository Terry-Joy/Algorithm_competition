#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=110;
char a[maxn],s[maxn],b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    { 
        scanf("%s",s+1);
        int sa=0,sb=0;
        int n=strlen(s+1);
        for(int i=1;i<=n;++i)
        { 
            if(s[i]&1)a[++sa]=s[i];
            else b[++sb]=s[i];
        }
        sort(a+1,a+sa+1);sort(b+1,b+1+sb);
        if(abs(b[1]-a[sa])!=1)
        {
            for(int i=1;i<=sa;++i)putchar(a[i]);
            for(int i=1;i<=sb;++i)putchar(b[i]);
            puts(""); 
        }
        else if(abs(a[1]-b[sb])!=1)
        {
            for(int i=1;i<=sb;++i)putchar(b[i]);
            for(int i=1;i<=sa;++i)putchar(a[i]);
            puts(""); 
        }
        else puts("No answer");
    }
    return 0; 
}
