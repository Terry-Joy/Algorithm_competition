#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int t,a,tot,tr[maxn<<2][3];
void build(int&p,int l,int r){ 
    p=++tot;
    if(l==r)return;
    if(l+1==r){ 
        int mid=l+r>>1;
        build(tr[p][0],l,l);
        build(tr[p][1],r,r);
        return;
    }
    int b=l+(r-l+3)/3-1;
    int c=b+r>>1;
    build(tr[p][0],l,b);
    build(tr[p][1],b+1,c);
    build(tr[p][2],c+1,r);
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        tot=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a);
        build(tr[0][0],1,n);
        cout<<tot<<"\n";
    }
    return 0;
}
