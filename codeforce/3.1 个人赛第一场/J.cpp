#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#define ll long long
using namespace std;

int main()
{
	int n,a[200005];
	scanf("%d",&n); 
	for(int i=1;i<=n;++i)
	 	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
        {
            i++;
            cnt++;
        }
    }
    printf("%d\n",cnt/2);
    return 0;
}
 
