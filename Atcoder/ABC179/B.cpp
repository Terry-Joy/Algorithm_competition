#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=105;
int d1[maxn],d2[maxn],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&d1[i],&d2[i]);
    for(int i=1;i<=n-2;++i){
        if(d1[i]==d2[i]&&d1[i+1]==d2[i+1]&&d1[i+2]==d2[i+2]){
            puts("Yes");return 0;
        }
    }
    puts("No");
    return 0;
}