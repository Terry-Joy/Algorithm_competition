#include<bits/stdc++.h>
using namespace std;
const int fr=50000;
int T,a,b,d,l,r,ip[50010],p[50010],sz,mu[50010],sum[50010];
long long ans;
void getmu(){
    mu[1]=1;
    sum[1]=1;
    for(int i=2;i<=fr;i++){
        if(!ip[i]){
            p[++sz]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=sz;j++){
            if(i*p[j]>fr){
                break;
            }
            ip[i*p[j]]=1;
            if(i%p[j]==0){
                break;
            }
            mu[i*p[j]]=-mu[i];
        }
        sum[i]=sum[i-1]+mu[i];
    }
}
void scan(int &x){
    char c=getchar();
    x=0;
    while('0'>c||c>'9'){
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        x*=10;
        x+=c-'0';
        c=getchar();
    }
}
void print(long long x){
    if(x>9){
        print(x/10);
    }
    putchar(x%10+'0');
}
int main(){

    scan(T);
    getmu();
    	for(int i=1;i<=10;++i)
		cout<<sum[i]<<" ";
    while(T--){
        scan(a);
        scan(b);
        scan(d);
        if(a>b){
            swap(a,b);
        }
        a/=d;//这里除以d之后分块的时候就不用除了
        b/=d;
        ans=0;
        l=1;
        while(l<=a){
            r=min(a/(a/l),b/(b/l));
            ans+=1ll*(sum[r]-sum[l-1])*(a/l)*(b/l);
            l=r+1;
        }
        print(ans);
        putchar('\n');
    }
    return 0;
}
