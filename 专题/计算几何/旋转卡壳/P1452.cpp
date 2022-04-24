#include<bits/stdc++.h>
#define cha(p1,p2,p3) (det(p2-p1,p3-p1))//p2-p1叉p3-p1
using namespace std;
int m=0,n;
const int maxn=5e4+5;
struct P{ //点向量类
    int x,y;
    P(int _x=0,int _y=0):x(_x),y(_y){ }
    P operator-(P p){ return P(x-p.x,y-p.y);}
    bool operator<(P p)const{//点按x排序后按y排序
        return (x!=p.x)?(x<p.x):(y<p.y);
    }
}p[maxn],ch[maxn];
int dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
void Andrew(){//求凸包 
	sort(p+1,p+n+1);//重载的排序
	for(int i = 1; i <=n; i++){
		while(m > 1 && cha(ch[m-2],ch[m-1],p[i]) <= 0) m--;//<=不需要共线点
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-1; i >= 1; i--){
		while(m > k && cha(ch[m-2],ch[m-1],p[i]) <= 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
}
int rotate_calipers(){//旋转卡壳凸包直径平方 直径相应改db和cha
    Andrew();
    int j=1,ans=0;//j上一次做完的点
    for(int i=0;i<m;++i){
        while(cha(ch[i],ch[i+1],ch[j])<cha(ch[i],ch[i+1],ch[j+1]))j=(j+1)%m;
        ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i].x>>p[i].y;
    cout<<rotate_calipers()<<"\n";
    return 0;
}
