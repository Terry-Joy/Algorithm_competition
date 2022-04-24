#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct FFT{
    struct cp{
        double x, y;
        friend cp operator + (const cp &a, const cp &b){
            return cp{a.x + b.x, a.y + b.y};
        }
        friend cp operator - (const cp &a, const cp &b){
            return cp{a.x - b.x, a.y - b.y};
        }
        friend cp operator * (const cp &a, const cp &b){
            return cp{a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
        }
    } A[maxn<<2], B[maxn<<2], C[maxn<<2];
    const double PI = acos(-1.0);
    int rev[maxn];
    void fft(cp A[], int len, int op){
        for(int i = 0; i < len; ++i) if(i < rev[i]) swap(A[i], A[rev[i]]);
        for(int i = 2; i <= len; i <<= 1){
            cp wn = {cos(2 * PI / i), sin(2 * PI / i)};
            int d = i >> 1;
            for(int j = 0; j < len; j += i){
                cp wk = {1, 0};
                for(int k = j; k < j + d; ++k, wk = wk * wn){
                    cp x = A[k], y = wk * A[k + d];
                    A[k] = x + y, A[k + d] = x - y;
                }
            }
        }
        if(op == -1){
            reverse(A + 1, A + len);
            for(int i = 0; i < len; ++i) A[i].x /= len;
        }
    }
    void work(int a[], int n, int b[], int m, int c[]){

        int len = 1;
        while(len <= n + m) len <<= 1;
        for(int i = 0; i < len; ++i){

            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
        }
        for(int i = 0; i < len; ++i){
            A[i].x=(i<=n)?a[i]:0;
            B[i].x=(i<=m)?b[i]:0;
            A[i].y=B[i].y=0;
        }
        fft(A, len, 1), fft(B, len, 1);
        for(int i = 0; i < len; ++i) C[i] = A[i] * B[i];
        fft(C, len, -1);
        for(int i = 0; i <= n + m; ++i) c[i] = (int)(C[i].x + 0.5);
    }
} fft; 
int n,a[maxn],x[maxn],y[maxn],c[maxn<<1];
int main(){ 
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),mx=max(mx,a[i]);
    if(n==1){ 
        puts("1");
        return 0;
    }else{ 
        mx++;
        for(int i=1;i<=n;++i)x[a[i]]=1,y[mx-a[i]]=1;
        fft.work(x,mx,y,mx,c);
        for(int i=2;i<=mx;++i){ 
            bool f=1;
            for(int j=i;j<=mx;j+=i){ 
                if(c[j+mx]){ 
                    f=0;break;       
                }
            }
            if(f){ 
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
