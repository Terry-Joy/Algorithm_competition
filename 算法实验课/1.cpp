#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C[32][32];
void init(){
    C[1][1]=1;
    for(int i=1;i<=30;++i){
        for(int j=1;j<=i;++j){
            if(j==1)C[i][j]=1;
            else
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j)
            cout<<C[i][j]<<" ";
        cout<<C[i][i]<<"\n";
    }   
    return 0;
}