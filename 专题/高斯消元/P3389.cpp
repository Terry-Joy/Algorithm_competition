#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=105;
int n;
db a[maxn][maxn];
struct Guass{
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
            return 1;//无穷解
        }
        for(int i=n-1;i>=0;--i){//回代
            for(int j=i+1;j<m;++j)
                a[i][m]=a[i][m]^(a[j][m]*a[i][j]);
        }
        return 0;//唯一解a[i][m]
    }

    int a[N][N],x[N];//解集
    bool freeX[N];//标记是否为自由变元
    int gcd(int a, int b) {return !b ? a : gcd(b, a % b);}
    int LCM(int a, int b) {return a / gcd(a, b) * b;}
    int solveMod(int equ, int var) { //返回自由变元个数
        /*初始化*/
        for (int i = 0; i <= var; i++) {
            x[i] = 0;
            freeX[i] = true;
        }
        /*转换为阶梯阵*/
        int r,c = 0; //当前处理的行、列
        for (r = 0; r < equ && c < var; r++, c++) { //枚举当前处理的行
            int mxr = r; //当前列绝对值最大的行
            for (int i = r + 1; i < equ; i++) //寻找当前列绝对值最大的行
                if (abs(a[i][c]) > abs(a[mxr][c]))
                    mxr = i;
            if (mxr != r) //与第r行交换
                for (int j = r; j < var + 1; j++)
                    swap(a[r][j], a[mxr][j]);
            if (a[r][c] == 0) { //c列第r行以下全是0，处理当前行的下一列
                r--;
                continue;
            }
            for (int i = r + 1; i < equ; i++) //枚举要删去的行
                if (a[i][c] != 0) {
                    int lcm = LCM(abs(a[i][c]), abs(a[r][c]));
                    int ta = lcm / abs(a[i][c]);
                    int tb = lcm / abs(a[r][c]);
                    if (a[i][c]*a[r][c] < 0) //异号情况相加
                        tb = -tb;
                    for (int j = c; j < var + 1; j++) 
                        a[i][j] = ((a[i][j] * ta - a[r][j] * tb) % MOD + MOD) % MOD;
                }
        }   
        //无解：化简的增广阵中存在(0,0,...,a)这样的行，且a!=0
        for (int i = r; i < equ; i++)
            if (a[i][c] != 0)
                return -1;
        //无穷解: 在var*(var+1)的增广阵中出现(0,0,...,0)这样的行
        int temp = var - r; //自由变元有var-r个
        if (r < var) //返回自由变元数
            return temp;
        //唯一解: 在var*(var+1)的增广阵中形成严格的上三角阵
        for (int i = var - 1; i >= 0; i--) { //计算解集
            int temp = a[i][var];
            for (int j = i + 1; j < var; j++) {
                if (a[i][j] != 0)
                    temp -= a[i][j] * x[j];
                temp = (temp % MOD + MOD) % MOD; //取模
            }
            while (temp % a[i][i] != 0) 
             //外层每次循环都是求a[i][i]，它是每个方程中唯一一个未知的变量
                temp += MOD; //a[i][i]必须为整数，加上周期MOD
                x[i] = (temp / a[i][i]) % MOD; //取模
        }
        return 0;
    }
}gauss;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n+1;++j)scanf("%lf",&a[i][j]);
    if(gauss.solve()!=0)puts("No Solution");
    else{
        for(int i=1;i<=n;++i)printf("%.2f\n",a[i][n+1]);
    }
    return 0;
}