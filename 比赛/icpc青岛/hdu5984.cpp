#include<bits/stdc++.h>

using namespace std;
typedef double db;
int main(){
    db d,L;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",&L,&d);
        if(L<=d)puts("0.000000");
        else 
            printf("%.6lf\n",log(L)-log(d)+1);
    }
    return 0;
}