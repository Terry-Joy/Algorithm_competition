#include<cmath>
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int maxn=32;
bitset<maxn>a[maxn];
int n;
struct Guass{
    int xorSolve(bitset<maxn>a[],int n,int m){//n*m a11x1^a12x2...a1m-1^xm-1=b1 
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
        return r;//解a[i][m]
    }
}gauss;
int mypow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n;++i)a[i].reset();
        int x,y;
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            a[i][n]=x;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            a[i][n]=a[i][n]^x;
        }
        for(int i=0;i<n;++i)a[i][i]=1;
        while(~scanf("%d%d",&x,&y)&&x&&y){
            a[y-1][x-1]=1;
        }
        int cnt=gauss.xorSolve(a,n,n);
        if(cnt==-1)puts("Oh,it's impossible~!!");
        else cout<<mypow(2,n-cnt)<<"\n";
    }
    return 0;
}