#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
int ans[maxn],t,n;
void ask(int op,int i,int j,int x){
    cout<<"? "<<op<<" "<<i<<" "<<j<<" "<<x<<endl;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)ans[i]=0;
        int pos=0,x;
        for(int i=1;i+1<=n;i+=2){
            ask(2,i,i+1,1);
            scanf("%d",&x);
            if(x==1){
                pos=i;break;
            }else if(x==2){
                ask(2,i+1,i,1);
                scanf("%d",&x);
                if(x==1){
                    pos=i+1;break;
                }
            }
        }
        if(!pos)pos=n;
        ans[pos]=1;
        for(int i=1;i<=n;++i){
            if(i!=pos){
                ask(1,pos,i,n-1);
                scanf("%d",&ans[i]);
            }
        }
        cout<<"!";
        for(int i=1;i<=n;++i){
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}