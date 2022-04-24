#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int a[maxn];
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        int i;   
        for(i=2;i<=n;++i)
           if (a[i]>=a[i-1])
              break; 
        if (i<=n)
           puts("YES");
        else puts("NO");
    } 
    return 0;
}
