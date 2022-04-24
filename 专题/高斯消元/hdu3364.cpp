#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=53;
bitset<maxn>a[maxn],b[maxn];
struct Guass{
    int xorSolve(bitset<maxn>a[],int n,int m){//(0,n-1)*(0,m) a11x1^a12x2...a1m-1^xm-1=b1 
        int r=0,c=0,mx;//注意bitset读进来的顺序 bitset最右方为0 
        for(;c<m;++c){//行列从0读入
            for(mx=r;mx<n;++mx){
                if(a[mx][c])break;//每列找按一个不为0的数丢最上面
            }
            if(mx==n)continue;
            if(!a[mx][c])continue;
            swap(a[mx],a[r]);
            for(int i=r+1;i<n;++i)
                if(a[i][c])
                    a[i]^=a[r];//下面全都消成0
            r++;
        }
        if(r<n){
            for(int i=r;i<n;++i)
                if(a[i][m])
                    return -1;//无解
            return r;//无穷解
        }
        for(int i=n-1;i>=0;--i){//回代
            for(int j=i+1;j<m;++j)
                a[i][m]=a[i][m]^(a[j][m]*a[i][j]);
        }
        return r;//唯一解a[i][m]
    }
}gauss;
int main(){
    int t,n,m,k;
    scanf("%d",&t);
    int T=0;
    while(t--){
        cout<<"Case "<<++T<<":\n";
        int x;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)a[i].reset();
        for(int i=0;i<m;++i){
            scanf("%d",&k);
            for(int j=0;j<k;++j){
                scanf("%d",&x);
                a[x-1][i]=1;
            }
        }
        scanf("%d",&k);
        for(int j=0;j<k;++j){
            for(int i=0;i<n;++i)b[i]=a[i];
            for(int i=0;i<n;++i){
                scanf("%d",&x);
                b[i][m]=x;
            }
            int cnt=gauss.xorSolve(b,n,m);
            if(cnt==-1)puts("0");
            else cout<<(1ll<<(m-cnt))<<"\n";
        }
    }
    return 0;
}