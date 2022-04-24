#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
const double eps=1e-5;
int n,f;
double a[maxn],b[maxn],mx[maxn];
bool check(double x){
    for(int i=1;i<=n;++i)b[i]=a[i]-x;
    for(int i=1;i<=n;++i)b[i]+=b[i-1],mx[i]=b[i];
    for(int i=1;i<=n;++i)mx[i]=min(mx[i],mx[i-1]);
    bool flag=0;
    for(int i=f;i<=n;++i){
        if(b[i]-mx[i-f]>=0){
            flag=1;break;
        }
    }
    if(!flag)return 0;
    else return 1;
}
int main(){
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
    double l=0,r=2000,mid;
    for(int i=1;i<=50;++i){
        mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%d",(int)(r*1000));
    return 0;
}
