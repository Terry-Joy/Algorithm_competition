
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
        if(1<=tx&&tx<=m&&1<=ty&&ty<=n){//ע�⣡���ڶ�ά������˵��x��y�У���ζ��x���������꣬y�Ǻ�������
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
                    Dfs(i,j); //���ѣ�����ͬһ��ͨ�������������
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

