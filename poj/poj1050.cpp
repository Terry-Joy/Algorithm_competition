#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105][105],ans,n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
           a[j][i]+=a[j-1][i]; 
    }
    ans=-2e9;
    int b=0;
    for(int i=1;i<=n;++i){ 
        for(int j=i;j<=n;++j){ 
            b=0; 
            for(int k=1;k<=n;++k){
                if(b>0)b+=a[j][k]-a[i-1][k];
                else b=a[j][k]-a[i-1][k];
                ans=max(ans,b);
            }
        } 
    }
    cout<<ans<<endl;
    return 0;
}
