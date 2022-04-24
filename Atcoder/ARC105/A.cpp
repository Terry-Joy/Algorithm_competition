#include<bits/stdc++.h>

using namespace std;

int a[5];
int main(){
    int s=0;
    for(int i=0;i<4;++i)
    scanf("%d",&a[i]),s+=a[i];
    int sum=0;
    for(int i=0;i<(1<<4);++i){
        sum=0;
        for(int j=0;j<4;++j){
            if(i&(1<<j))sum+=a[j];
        }
        if(sum==s-sum){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}