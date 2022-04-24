//求单位根
#include<bits/stdc++.h>
const int Maxn 1000500
//用这句话能得到得到精确的π,可以当做结论来记
const double Pi=acos(-1.0);
using namespace std;
struct CP{
  CP (double xx=0,double yy=0){x=xx,y=yy;}
  double x,y;
  CP operator + (CP const &B) const
  {return CP(x+B.x,y+B.y);}
  CP operator - (CP const &B) const
  {return CP(x-B.x,y-B.y);}
  CP operator * (CP const &B) const
  {return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
  //除法没用
}w[Maxn];
int n;
int main(){
    scanf("%d",&n);
    CP sav(cos(2*Pi/n),sin(2*Pi/n)),buf(1,0);
    for (int i=0;i<n;i++){
        w[i]=buf;
        buf=buf*sav;
    }
    for (int i=0;i<n;i++)
      printf("w[%d][n]=(%.4lf,%.4lf)\n",i,w[i].x,w[i].y);
    //由于精度问题会出现-0.0000的情况,将就看吧
    return 0;
}

//DFT (分治由系数表达求点值表达)
#include<bits/stdc++.h>
using namespace std;
const int maxn=1350000;
const double Pi=acos(-1.0);
int n,m;
struct CP{
    CP(double xx=0,double yy=0){x=xx;y=yy;}
    double x,y;
    CP operator+(CP const&B)const
    {return CP(x+B.x,y+B.y);}
    CP operator -(CP const&B)const
    {return CP(x-B.x,y-B.y);}
    CP operator *(CP const&B)const
    {return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
    CP operator / (CP const&B)const{//除法在此没用
        double t=B.x*B.x+B.y*B.y;
        return CP((x*B.x+y*B.y)/t,(y*B.x-x*B.y)/t);
    }
}f[maxn<<1],sav[maxn<<1];
void dft(CP*f,int len){
    if(len==1)return;
    CP*fl=f,*fr=f+len/2;
    for(int k=0;k<len;++k)sav[k]=f[k];
    for(int k=0;k<len/2;++k){
        fl[k]=sav[k<<1];fr[k]=sav[k<<1|1];
    }
    dft(fl,len/2);
    dft(fr,len/2);
     //由于每次使用的单位根次数不同(len次单位根),所以要重新求。
     CP tG(cos(2*Pi/len),sin(2*Pi/len)),buf(1,0);
    for (int k=0;k<len/2;k++){
        //这里buf = (len次单位根的第k个) 
        sav[k]=fl[k]+buf*fr[k];//(1) 两个原理式子
        sav[k+len/2]=fl[k]-buf*fr[k];//(2)
        buf=buf*tG;//得到下一个单位根。
    }
    for (int k=0;k<len;k++)f[k]=sav[k];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%lf",&f[i].x);
      //一开始都是实数,虚部为0
    for(m=1;m<n;m<<=1)
     //把长度补到2的幂,不必担心高次项的系数,因为默认为0
    dft(f,m);
    for(int i=0;i<m;++i)
       printf("(%.4f,%.4f)\n",f[i].x,f[i].y);
    return 0;
}
//idft 由点值求系数
void idft(CP *f,int len){
  if (len==1)return ;//边界
  //指针的使用比较巧妙 
  CP *fl=f,*fr=f+len/2;
  for (int k=0;k<len;k++)sav[k]=f[k];
  for (int k=0;k<len/2;k++)//分奇偶打乱
    {fl[k]=sav[k<<1];fr[k]=sav[k<<1|1];}
  idft(fl,len/2);
  idft(fr,len/2);//处理子问题
  CP tG(cos(2*Pi/len),  - sin(2*Pi/len)),buf(1,0);
               //注意这 ↑ 个负号! 
  for (int k=0;k<len/2;k++){
    //这里buf = (len次反单位根的第k个) 
    CP tt=buf*fr[k];
    sav[k]=fl[k]+tt;
    sav[k+len/2]=fl[k]-tt;
    buf=buf*tG;//得到下一个反单位根。
  }
  for (int k=0;k<len;k++)f[k]=sav[k];
}

//迭代版FFT 最经典
#include<bits/stdc++.h>
const int Maxn=1350000
using namespace std;
const double Pi=acos(-1.0);
int n,m;
struct CP{
  CP (double xx=0,double yy=0){x=xx,y=yy;}
  double x,y;
  CP operator + (CP const &B) const
  {return CP(x+B.x,y+B.y);}
  CP operator -(CP const &B) const
  {return CP(x-B.x,y-B.y);}
  CP operator * (CP const &B) const
  {return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
}f[Maxn<<1],p[Maxn<<1];//数组最大(n+m)<<1 四倍空间
int tr[Maxn<<1];
void fft(CP *f,bool flag){//flag==1 DFT 否则 IDFT
  for (int i=0;i<n;i++)
    if (i<tr[i])swap(f[i],f[tr[i]]);//FFT前交换分治最后彼此翻转的数
  //枚举区间长度 
  for(int p=2;p<=n;p<<=1){
    int len=p>>1; //待合并的长度
    CP tG(cos(2*Pi/p),sin(2*Pi/p));
    if(!flag)tG.y*=-1;  //p次单位根
    for(int k=0;k<n;k+=p){  //枚举起始点 
      CP buf(1,0);  //遍历一个子问题并合并
      for(int l=k;l<k+len;l++){
        CP tt=buf*f[len+l];
        f[len+l]=f[l]-tt;
        f[l]=f[l]+tt;
        buf=buf*tG;
      }
    }
  }
}
int main()
{
  scanf("%d%d",&n,&m);
  for (int i=0;i<=n;i++)scanf("%lf",&f[i].x);
  for (int i=0;i<=m;i++)scanf("%lf",&p[i].x);
  for(m+=n,n=1;n<=m;n<<=1);//数组(n+m)<<1
  for(int i=0;i<n;i++)
    tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
  fft(f,1);fft(p,1);//DFT
  for(int i=0;i<n;++i)f[i]=f[i]*p[i];
  fft(f,0);
  for(int i=0;i<=m;++i)printf("%d ",(int)(f[i].x/n+0.5));
  return 0;
}

//三次变两次优化 
#define Maxn 1350000
using namespace std;
const double Pi=acos(-1);
int n,m;
struct CP
{
  CP (double xx=0,double yy=0){x=xx,y=yy;}
  double x,y;
  CP operator + (CP const &B) const
  {return CP(x+B.x,y+B.y);}
  CP operator - (CP const &B) const
  {return CP(x-B.x,y-B.y);}
  CP operator * (CP const &B) const
  {return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
}f[Maxn<<1];//只用了一个复数数组 
int tr[Maxn<<1];
void fft(CP *f,bool flag)
{
  for (int i=0;i<n;i++)
    if (i<tr[i])swap(f[i],f[tr[i]]);
  for(int p=2;p<=n;p<<=1){
    int len=p>>1;
    CP tG(cos(2*Pi/p),sin(2*Pi/p));
    if(!flag)tG.y*=-1;
    for(int k=0;k<n;k+=p){
      CP buf(1,0);
      for(int l=k;l<k+len;l++){
        CP tt=buf*f[len+l];
        f[len+l]=f[l]-tt;
        f[l]=f[l]+tt;
        buf=buf*tG;
      }
    }
  }
}
int main()
{
  scanf("%d%d",&n,&m);
  for (int i=0;i<=n;i++)scanf("%lf",&f[i].x);
  for (int i=0;i<=m;i++)scanf("%lf",&f[i].y)
  for(m+=n,n=1;n<=m;n<<=1);
  for(int i=0;i<n;i++)
    tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
  fft(f,1);
  for(int i=0;i<n;++i)f[i]=f[i]*f[i];
  fft(f,0);
  for(int i=0;i<=m;++i)
    printf("%d ",(int)(f[i].y/n/2+0.5));
  return 0;
}
