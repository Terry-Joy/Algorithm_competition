#include<iostream>
#include<cstdio>

using namespace std;
typedef long long ll;
const int maxn=1e4+5;
int a[maxn],sum;
int ask(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>sum;
    return sum;
}
int main(){ 
    int n;
    cin>>n;
    int id=1;
    for(int i=2;i<=n;++i){  
        int s1=ask(id,i),s2=ask(i,id);
        if(s1<s2)a[i]=s2;
        else{
            a[id]=s1;
            id=i;
        }
    }
    a[id]=n;
    cout<<"!";
    for(int i=1;i<=n;++i)
        cout<<" "<<a[i];
    cout<<endl;
    return 0;
}
