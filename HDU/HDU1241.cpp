
#include <stdio.h>
#include <string.h>
#include <queue>
 
using namespace std;
const int maxn=105;
char mat[maxn][maxn];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int  m,n;
int sum;
void Dfs(int x,int y){
    int tx;
    int ty;
    for(int i=0;i<8;i++){
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(1<=tx&&tx<=m&&1<=ty&&ty<=n){//注意！对于二维数组来说，x行y列，意味着x是纵向坐标，y是横向坐标
            if(mat[tx][ty]=='@'){
                mat[tx][ty]='*';
                Dfs(tx,ty);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)){
        if(m==0&&n==0){
            break;
        }
        //memset(mat,0,sizeof(mat));
        sum=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //scanf("%s",mat[i]+1);
                cin>>mat[i][j];
                //scanf("%c",&mat[i][j]);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mat[i][j]=='@'){
                    sum++;
                    mat[i][j]='*';
                    Dfs(i,j); //深搜，消除同一连通块的所有油田标记
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

