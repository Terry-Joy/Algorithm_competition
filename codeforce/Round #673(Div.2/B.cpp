#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn];
bool f[maxn];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)f[i]=0;
        if(k&1){ 
            for(int i=1;i<=n;++i){ 
                if(a[i]&1)f[i]=1;
                else f[i]=0;
            }
        }else{ 
            bool tmp=0;
            int m=k/2;
            for(int i=1;i<=n;++i){ 
                if(a[i]<m)f[i]=0;
                else if(a[i]>m)f[i]=1;
                else{ 
                    f[i]=tmp;
                    tmp=!tmp;
                }
            }
        }
        for(int i=1;i<=n;++i)
            cout<<f[i]<<" ";
        puts("");
    }
    return 0;
}
