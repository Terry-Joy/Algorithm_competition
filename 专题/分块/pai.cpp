#include<iostream>
#include<ctime>
using namespace std;
int a[20];
int main(){
    freopen("data.in","w",stdin);
    srand(time(0));
    int n,m;
    n=m=10;
    cout<<n<<"\n";
    for(int i=1;i<=n;++i)a[i]=rand()%100+1;
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    cout<<endl;
    int l,r;
    for(int i=1;i<=n;++i){
        l=rand()%10+1;r=rand()%10+1;
        if(l>r)swap(l,r);
        cout<<l<<" "<<r<<"\n";
    }
    cout<<m<<"\n";
    int op;
    for(int i=1;i<=m;++i){
        op=rand()%2+1;
        l=rand()%10+1;r=rand()%10+1;
        if(l>r)swap(l,r);
        cout<<op<<" "<<l<<" "<<r<<"\n";
    }
    return 0;
}