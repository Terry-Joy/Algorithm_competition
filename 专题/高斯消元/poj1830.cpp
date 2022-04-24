#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[32][32],x[32],freeX[32],st[32],ed[32];
int Gauss(int equ,int var){
    for(int i=0;i<=var;++i){
        x[i]=0;
        freeX[i]=1;
    }
    int col=0,row;
    for(row=0;row<equ&&col<var;row++,col++){
        int mx=row;
        for(int i=row+1;i<equ;++i){
            if(abs(a[i][col])>abs(a[mx][col]))
                mx=i;
        }
        if(mx!=row){
            for(int j=row;j<var+1;++j)
                swap(a[row][j],a[mx][j]);
        }
        if(a[row][col]==0){
            row--;
            continue;
        }
        for(int i=row+1;i<equ;++i){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;++j){
                    a[i][j]^=a[row][j];
                }
            }
        }
    }
    for(int i=row;i<equ;++i)//无解
        if(a[i][col]!=0)return -1;
    return var-row;
}
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
    int n,x,y,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            for(int j=0;j<n+1;++j)
                a[i][j]=0;
        for(int i=0;i<n;++i) scanf("%d",&st[i]);
        for(int i=0;i<n;++i) scanf("%d",&ed[i]);
        for(int i=0;i<n;++i)
            a[i][n]=st[i]^ed[i],a[i][i]=1;
        while(~scanf("%d%d",&x,&y)&&(x|y))
            a[y-1][x-1]=1;
        int flag=Gauss(n,n);
        if(flag==-1)
            puts("Oh,it's impossible~!!");
        else
            cout<<mypow(2,flag)<<"\n";
    }
    return 0;
}
