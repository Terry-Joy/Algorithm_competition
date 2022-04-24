#include<iostream>
#include<ctime>
#include<cstdio>
using namespace std;

int main(){ 
    freopen("4.in","w",stdout);
    cout<<1<<endl;
    cout<<1000000<<endl;
    for(int i=1;i<=1000000;++i){
        cout<<(i&1)<<" ";
    }
    return 0;
}
