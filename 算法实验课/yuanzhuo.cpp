#include<bits/stdc++.h>
using namespace std;
bool is[155][275];
struct P{
    int id,c;
}a[155];
struct Z{
    int id,r;
}z[280];
bool cmp1(P&a,P&b){
    return a.c>b.c;
}
bool cmp2(Z&a,Z&b){
    return a.r>b.r;
}
int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)scanf("%d",&a[i].c),a[i].id=i;
    sort(a+1,a+1+m,cmp1);
    for(int i=1;i<=n;++i)scanf("%d",&z[i].r),z[i].id=i;
    sort(z+1,z+1+n,cmp2);
    bool ok=1;
    int j=1;
    for(int i=1;i<=m;++i){
        if(!ok)break;
        while(a[i].c){
            if(is[a[i].id][z[j].id]){
                ok=0;break;
            }
            if(z[j].r){
                is[a[i].id][z[j].id]=1;
                a[i].c--;
                z[j].r--;
            }
            j=((j+1==n+1)?1:j+1);
        }
    }
    if(!ok)puts("0");
    else{
        puts("1");
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j)
              if(is[i][j]){
                cout<<j<<" ";
            }
            puts("");
        }
    }
    return 0;
}