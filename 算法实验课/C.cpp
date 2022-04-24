#include<bits/stdc++.h>
using namespace std;
typedef double db;
int n=3;
db a[10][10];
const db eps=1e-6;
  int solve(){//n*n正常消元 枚举列初等行变消阶梯型,再回代得出答案
        int r,c;//当前最左列最上行
        for(c=1,r=1;c<=n;++c){
            int t=r;
            for(int i=r+1;i<=n;++i){
                if(fabs(a[i][c])>fabs(a[t][c]))
                    t=i;//找最大值的行
            }
            if(fabs(a[t][c])<eps)continue;
            for(int i=c;i<=n+1;++i)swap(a[t][i],a[r][i]);//丢到最上面的行
            for(int i=n+1;i>=c;--i)a[r][i]/=a[r][c];//第一个数变1
            for(int i=r+1;i<=n;++i)
                if(fabs(a[i][c])>eps)
                    for(int j=n+1;j>=c;--j)//下面行清零
                        a[i][j]-=a[r][j]*a[i][c];
            r++;
        }
        if(r<=n){
            for(int i=r;i<=n;++i)
                if(fabs(a[i][n+1])>eps)return -1;//非0 无解
            return 1;//无穷解
        }//回代求解
        for(int i=n;i>=1;--i)
            for(int j=i+1;j<=n+1;++j)
                a[i][n+1]-=a[j][n+1]*a[i][j];
        return 0;//唯一解 看情况return row统计个数
    }
int main(){
    for(int i=1;i<=3;++i)
        for(int j=1;j<=4;++j)cin>>a[i][j];
    solve();
    cout<<a[1][n+1]<<" "<<a[2][n+1]<<" "<<a[3][n+1];
    return 0;
}