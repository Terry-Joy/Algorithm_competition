#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],b[maxn];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i==n){
            b[i]=a[i];
            continue;
        }
        if(a[i]==a[i+1]){
            b[i]=(a[i-1]+a[i]+a[i+1])/2;
            continue;
        }
        int j;
        for(j=i;j<n;j++){
            if(a[j]==a[j+1])
                break;
        }
        if((j-i+1)<=2){
            if(i==1)
                b[i]=a[i];
            else
                b[i]=(a[i-1]+a[i]+a[i+1])/2;
            continue;
        }
        if(j==n&&(j-i+1)<=3){
            ans = max(ans,1);
            b[i]=(a[i-1]+a[i]+a[i+1])/2;
            continue;
        }
        int flag = 0;
        if((j-i+1)%2==0){
             ans = max((j-i+1)/2-1,ans);
            for(int k=i;k<i+(j-i+1)/2;k++)
                b[k]=a[i];
            for(int k=i+(j-i+1)/2;k<=j;k++)
                b[k]=1-a[i];
        }
        else{
             ans = max((j-i+1)/2,ans);
            for(int k=i;k<=j;k++)
                b[k]=a[i];
        }
        i=j;
    }
    b[1]=a[1];
    b[n]=a[n];
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    puts("");
}
