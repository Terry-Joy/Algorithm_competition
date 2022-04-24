#include<bits/stdc++.h>

using namespace std;
typedef double db;
const db eps=1e-8;
int sign(db a){
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){
    return sign(a-b);
}
int n;
bool v[2005][2005];
int a,b,c,d,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a==c||b==d)continue;
        if(a>c)swap(a,c),swap(b,d);
        db k=1.0*(d-b)/(c-a);
        db b2=1.0*b-k*a;
        for(int j=a;j<c;++j){
            db y_1=k*j+b2;
            db y_2=k*(j+1)+b2;
            if(dcmp(y_1,y_2)>0)swap(y_1,y_2);
            int ymn=(int)(y_1+eps);
            int ymx=(int)(y_2+1-eps);
            for(int f=ymn;f<ymx;++f)
                v[j][f]=1;
        }
    }
    for(int i=0;i<=2000;++i)
        for(int j=0;j<=2000;++j)
            if(v[i][j])ans++;
    cout<<ans<<"\n";
    return 0;
}