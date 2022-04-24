
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>

using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int m=0x7FFFFFFF;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)b[i]=a[i],m=min(m,a[i]);
        sort(a+1,a+1+n);
        bool f=1;
        for(int i=1;i<=n;++i){
            if(b[i]!=a[i]){
                if(b[i]%m!=0){
                    f=0;
                    break;
                }
            }
        }
        if(!f)puts("NO");
        else puts("YES");
    }
    return 0;
}