#include<bits/stdc++.h>
using namespace std;
int a[210],ans,len1,len2,n;
int main(){
    while(~scanf("%d",&n)&&n){
        ans=len1=len2=0;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i+n]=a[i];
        for(int i=2;i<=2*n;++i){
            if(a[i]>a[i-1])len1++,ans=max(ans,len1);
            else len1=0;
            if(a[i]<a[i-1])len2++,ans=max(ans,len2);
            else len2=0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}