
#include<bits/stdc++.h>
#define db double
#define ld long double;
using namespace std;
typedef long long ll;
const int maxn=105;
pair<db,db>a[maxn];
const db INF=0x3f3f3f3f;
db x0,y3,x1,y4,x2,y2;
db s1(db x,db y){
    return fabs((y4-y3)*x-(x1-x0)*y+y3*(x1-x0)-(y4-y3)*x0);
}
db s2(db x,db y){
    return fabs((y2-y3)*x-(x2-x0)*y+y3*(x2-x0)-(y2-y3)*x0);
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf",&x0,&y3,&x1,&y4,&x2,&y2);
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%lf%lf",&a[i].first,&a[i].second);
        }
        cout<<s1(a[2].first,a[2].second)<<" "<<s2(a[2].first,a[2].second)<<"\n";
        for(int i=1;i<=n;++i)
            printf("%.6lf\n",min(s1(a[i].first,a[i].second),s2(a[i].first,a[i].second)));
    }
    return 0;
}