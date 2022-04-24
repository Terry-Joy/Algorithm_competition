#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
#define diss(a,b) sqrt(dis(a,b))
using namespace std;
using db=double;
const db eps=1e-8;
const db INF=1e18;
int n,xb,yb,xm,ym;
int sign(db a){
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){
    return sign(a-b);
}
struct P{
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){}
    P operator-(P p){
        return P(x-p.x,y-p.y);
    }
    db len2(){
        return x*x+y*y;
    }
    db len(){return sqrt(len2());}
	bool operator<(const P p)const{
		int c=dcmp(x,p.x);
		if(c)return c==-1;
		return dcmp(y,p.y)==-1;
	}
};
struct Cir{
    db r;
    P c;
    Cir(P _c=P(),db _r=0):c(_c),r(_r){}
};
db det(P a,P b){
    return a.x*b.y-a.y*b.x;
}
db dot(P a,P b){
	return a.x*b.x+a.y*b.y;
}
struct L{
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}
    L(P X=P(),P Y=P()){
        ps[0]=X,ps[1]=Y;
    }
};
db dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
db PLinedis(L l1,P a){
    return fabs(det(a-l1.ps[0],l1.dir())/l1.dir().len());
}

int relationCir(Cir x,Cir y){
    db d=sqrt(dis(x.c,y.c));
    int f1=sign(d-x.r-y.r);
    if(f1>0)return 4;
    if(!f1)return 3;
    db l=fabs(x.r-y.r);
    int f2=sign(d-l);
    if(f1<0&&f2>0)return 2;
    if(!f2)return 1;
    if(f2<0)return 0;
}
bool parallel(L x1,L x2){
	P a=x2.ps[1]-x1.ps[1];
	return sign(det(x1.dir(),x2.dir())==0&&sign(det(x2.dir(),a))!=0);
}
P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}

void getCircleLineSec(P c,db r,P p1,P p2,vector<P>&ans){//圆与直线交点 重点就2个一样
    P p=c;
    db t;
    p.x+=p1.y-p2.y;
    p.y+=p2.x-p1.x;
    p=LineInter(L(p,c),L(p1,p2));
    t=sqrt(r*r-diss(p,c)*diss(p,c))/diss(p1,p2);
    P x1,x2;
    x1={p.x+(p2.x-p1.x)*t,p.y+(p2.y-p1.y)*t};
    x2={p.x-(p2.x-p1.x)*t,p.y-(p2.y-p1.y)*t};
    
    ans.pb(x1);ans.pb(x2);
}
void getCircleIntersec(P c1,db r1,P c2,db r2,vector<P>&ans){//圆与圆交点 要保证有交点圆心不重合 先判了圆的关系
    P u,v;
    db t;
    t=(1+(r1*r1-r2*r2)/diss(c1,c2)/diss(c1,c2))/2;
    u.x=c1.x+(c2.x-c1.x)*t;
    u.y=c1.y+(c2.y-c1.y)*t;
    v.x=u.x+c1.y-c2.y;
    v.y=u.y-c1.x+c2.x;
    getCircleLineSec(c1,r1,u,v,ans);
}
int CirL(L a,Cir b){
    db Len=PLinedis(a,b.c);
    if(dcmp(Len,b.r)>0)return 0;//li
    else if(dcmp(Len,b.r)==0)return 1;//qie
    else return 2; //jiao
}
Cir read_cir(){
    Cir C;
    cin>>C.c.x>>C.c.y>>C.r;
    return C;
}
bool operator==(P a,P b){
    return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);
}
vector<Cir>cir,tmpcir;
vector<pair<int,db>>mp[100000];
bool onSeg(P c,P a,P b){
	return sign(det(c-a,b-a)==0)&&sign(dot(c-a,c-b))<=0;
} 
bool direct(L x){
	vector<pair<P,int>>sec;
	P a=x.ps[0],b=x.ps[1];
	if(a<b)swap(a,b);
	sec.push_back({a,-2});
	sec.push_back({b,2});
	for(auto&u:cir){
		if(CirL(x,u)==2){
			vector<P>tmpjiao;
			getCircleLineSec(u.c,u.r,x.ps[0],x.ps[1],tmpjiao);
			if(tmpjiao[0]<tmpjiao[1])swap(tmpjiao[0],tmpjiao[1]);
			sec.push_back({tmpjiao[0],0});
			sec.push_back({tmpjiao[1],1});
		}
	}
	sort(sec.begin(),sec.end());
	bool ret = true, counting = false;
	int inside = 0;
	for(int i=0; i < sec.size(); i++) {
		if(abs(sec[i].se) == 2) counting = !counting;
		else sec[i].se ? inside-- : inside++;
		
		if(counting and !inside) ret = false;
	}
	return ret;
}
using DI=pair<db,int>;
vector<db>f;
void dij(int tot,int st){
	priority_queue<DI,vector<DI>,greater<DI>>q;
	f.resize(tot);
	for(int i=0;i<tot;++i)f[i]=INF;
	f[st]=0;q.push({0,st});
	while(!q.empty()){
		auto it=q.top();
		q.pop();
		int x=it.se;
		if(dcmp(it.fi,f[it.se])>0)continue;
		for(auto u:mp[x]){
			if(dcmp(f[u.fi],f[x]+u.se)>0){
				f[u.fi]=f[x]+u.se;
				q.push({f[u.fi],u.fi});
			}
		}
	}
}
int main(){
    cin>>xb>>yb>>xm>>ym;
	cin>>n;
    tmpcir.resize(n);
    for(int i=0;i<n;++i){  
        tmpcir[i]=read_cir();
    }
	if(P(xb,yb)==P(xm,ym)){
		cout<<"0.000000000"<<'\n';
		return 0;
	}
    vector<bool>is;
    is.resize(n);
    for(int i=0;i<tmpcir.size();++i){
        for(int j=i+1;j<tmpcir.size();++j){
            int flag=relationCir(tmpcir[i],tmpcir[j]);
            if(flag==1||flag==0){
                if(dcmp(tmpcir[i].r,tmpcir[j].r)>0){
                    is[j]=1;
                }else
                    is[i]=1;
            }
        }
    }
   // cout<<tmpcir.size()<<"\n";
    for(int i=0;i<tmpcir.size();++i){
        if(!is[i])cir.push_back(tmpcir[i]);
    }
   // cout<<cir.size()<<"\n";
    vector<P>tmp;
    for(int i=0;i<cir.size();++i){
        for(int j=i+1;j<cir.size();++j){
            int flag=relationCir(cir[i],cir[j]);
            if(flag==4)continue;
            vector<P>jiao;
            getCircleIntersec(cir[i].c,cir[i].r,cir[j].c,cir[j].r,jiao);
            if(flag==3){
                tmp.push_back(jiao[0]);
				//cout<<jiao[0].x<<" "<<jiao[0].y<<"\n";
			}
            else{
                tmp.push_back(jiao[0]);
                tmp.push_back(jiao[1]);
            }
        }
    }
    //cout<<tmp.size()<<"\n";
    bool f1=0,f2=0;
	int s=-1,t=-1;
//	cout<<tmp[0].x<<" "<<tmp[0].y<<"\n"; 
    for(int i=0;i<tmp.size();++i){
        if(tmp[i]==P(xb,yb))s=i;
        if(tmp[i]==P(xm,ym))t=i;
    }
    if(s==-1){
		tmp.push_back({xb,yb});
		s=tmp.size()-1;
	}
    if(t==-1){
		tmp.push_back({xm,ym});
		t=tmp.size()-1;
	}
//	cout<<tmp.size()<<"\n";
    int num=tmp.size();

    for(int i=0;i<num;++i){
        for(int j=i+1;j<num;++j){
            if(direct(L(tmp[i],tmp[j]))){
                db dd=diss(tmp[i],tmp[j]);
                mp[i].push_back({j,dd});
                mp[j].push_back({i,dd});
            }
        }
    }
	dij(num,s);
	//printf("%.10lf\n",f[t]); 
	if(f[t]==INF)cout<<"impossible"<<"\n";
	else cout<<fixed<<setprecision(12)<<f[t]<<"\n";
    return 0;
}