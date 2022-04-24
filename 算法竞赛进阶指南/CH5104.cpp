#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 16;

struct S{
    int i, j, l, r, x, y;
}pre[N][N * N][N][N][2][2], t;

int n, m, k, a[N][N], f[N][N * N][N][N][2][2];
int ans = 0;

int inline cost(int i, int l, int r){
    return a[i][r] - a[i][l - 1];
}

void print(S x){
    if(x.j == 0) return;
    print(pre[x.i][x.j][x.l][x.r][x.x][x.y]);		//递归调用上一层 
    for(int i = x.l; i <= x.r; i++) 				//从头节点开始输出 
        printf("%d %d\n", x.i, i);
}

int main(){
    memset(f, 0xcf, sizeof f);
    
    scanf("%d%d%d", &n, &m, &k);
    for(int r = 0; r <= n; r++) {
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++)
                f[r][0][i][j][0][0] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), a[i][j] += a[i][j - 1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int l = 1; l <= m; l++){
                for(int r = l; r <= m; r++){
                    if(j < r - l + 1) continue;
                    
                    //x = 0, y = 0;
                    for(int l1 = l; l1 <= r; l1++){
                        for(int r1 = l1; r1 <= r; r1++){
                            int &v = f[i][j][l][r][0][0], val = f[i - 1][j - (r - l + 1)][l1][r1][0][0] + cost(i, l, r);
                            if(v < val) {
                                v = val, pre[i][j][l][r][0][0] = (S){i - 1, j - (r - l + 1), l1, r1, 0, 0};
                            }
                        }
                    }
                    //x = 0, y = 1;
                    for(int l1 = l; l1 <= r; l1++){
                        for(int r1 = r; r1 <= m; r1++){
                            for(int y1 = 0; y1 < 2; y1++) {
                                int &v = f[i][j][l][r][0][1], val = f[i - 1][j - (r - l + 1)][l1][r1][0][y1] + cost(i, l, r);
                                if(v < val) {
                                    v = val, pre[i][j][l][r][0][1] = (S){i - 1, j - (r - l + 1), l1, r1, 0, y1};
                                }
                            }
                        }
                    }

                    // x = 1, y = 0;		左边0递减，右边0递增 
                    for(int l1 = 1; l1 <= l; l1++){
                        for(int r1 = l; r1 <= r; r1++){
                            for(int x1 = 0; x1 < 2; x1++) {
                                int &v = f[i][j][l][r][1][0], val = f[i - 1][j - (r - l + 1)][l1][r1][x1][0] + cost(i, l, r);
                                if(v < val) {
                                    v = val, pre[i][j][l][r][1][0] = (S){i - 1, j - (r - l + 1), l1, r1, x1, 0};
                                }   
                            }
                        }
                    }

                    // x = 1, y = 1; 
                    for(int l1 = 1; l1 <= l; l1++){		//l1,r1枚举上一层的l,r 
                        for(int r1 = r; r1 <= m; r1++){
                            for(int x1 = 0; x1 < 2; x1++) {
                                for(int y1 = 0; y1 < 2; y1++) {
                                    int &v = f[i][j][l][r][1][1], val =  f[i - 1][j - (r - l + 1)][l1][r1][x1][y1] + cost(i, l, r);
                                    if(v < val) {
                                        v = val, pre[i][j][l][r][1][1] = (S){i - 1, j - (r - l + 1), l1, r1, x1, y1};
                                    }
                                }
                            }
                        }
                    }
                    if(j == k){
                        for(int x = 0; x < 2; x++) {
                            for(int y = 0; y < 2; y++) {
                                if(ans < f[i][j][l][r][x][y]) {
                                    ans = f[i][j][l][r][x][y], t = (S){i, j, l, r, x, y};
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Oil : %d\n", ans);
    print(t);
    return 0;   
}
