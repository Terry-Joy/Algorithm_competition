#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt[102],a;
int main(){ 
    int n;
    while(~scanf("%d",&n)&&n){ 
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;++i)scanf("%d",&a),cnt[a]++;
        int first=1;
        for(int i=1;i<=100;++i)
            for(int j=1;j<=cnt[i];++j){ 
                if(!first)printf(" ");
                first=0;
                printf("%d",i);
            }
        puts("");
    }
    return 0;
}
