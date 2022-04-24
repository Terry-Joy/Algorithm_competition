#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e8+5;
int x[30]={0,4,14,52,194,724,2702,10084,100000000};
char s[40];
int main(){
    int t;
    bool f=1;
            for(int i=-100;i<=100;++i){
                for(int j=-100;j<=100;++j){
                    f=1;
                    for(int k=3;k<=7;++k){
                        if(x[k]!=i*x[k-1]+j*x[k-2]){
                           f=0;
                        }
                           if(!f)break;
                    }
                    if(f)cout<<i<<" "<<j<<" ";
                }
            }
    return 0;
}