
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int zero=255,one=256,tmp=257,tmp2=258,tmp3=259,cnt=0;
void add(int a,int b,int c){
    cout<<"+ "<<a<<" "<<b<<" "<<c<<endl;cnt++;
}
void lt(int a,int b,int c){
    cout<<"< "<<a<<" "<<b<<" "<<c<<endl;cnt++;
}
void pow(int a,int b){
    for(int i=1;i<=b;i++){
        add(a,a,a);
    }
}
void mul(int a,int b,int c){
    lt(a,zero,b);
    lt(tmp,zero,c);
    add(a,a,tmp);
    lt(a,one,a);
}

void fenjie(int base,int aim){
    add(tmp,zero,zero);
    for(int i=30;i>=0;i--){
        add(tmp2,zero,one);
        pow(tmp2,i);
        add(tmp2,tmp2,tmp);
        add(tmp3,one,aim);
        lt(tmp2,tmp2,tmp3);
        add(base+i,zero,tmp2);
        pow(tmp2,i);
        add(tmp,tmp,tmp2);
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    // init
    cout<<8992<<endl;
    lt(one,zero,0);

    fenjie(32,0);
    fenjie(64,1);

    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            int now=i+j+128;
            mul(tmp2,i+32,j+64);
            add(now,now,tmp2);
        }
    }
    for(int i=0;i<=60;i++){
        add(i+192,zero,i+128);
        pow(i+192,i);
        add(2,2,i+192);
    }
}
