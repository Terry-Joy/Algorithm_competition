inline int read(){
    char c = getchar();int x = 0;
    while(c < '0' || c > '9') {c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x;
}
inline void in(int&x){
    x=read();
}