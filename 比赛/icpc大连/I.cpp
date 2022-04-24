#include<bits/stdc++.h>

using namespace std;
const double Pi=acos(-1.0);
int main(){ 
    int n,d;
    while(~scanf("%d%d",&n,&d)){ 
        int a;
        double ans=0;
        for(int i=1;i<=n;++i){ 
            cin>>a;
            ans+=0.5*sin(1.0*a*Pi/180)*d*d;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
