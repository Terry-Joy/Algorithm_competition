const db EPS=1e-8;
typedef struct P3D {
    db x, y, z;
    P3D(db xx = 0, db yy = 0, db zz = 0): x(xx), y(yy), z(zz) {}
    bool operator == (const P3D& A) const {
        return x==A.x && y==A.y && z==A.z;
    }
}V3D;
 
P3D read_Point_3D() {
    db x,y,z;
    scanf("%lf%lf%lf",&x,&y,&z);
    return P3D(x,y,z);
}
 
V3D operator + (const V3D & A, const V3D & B) {
    return V3D(A.x + B.x, A.y + B.y, A.z + B.z);
}
 
V3D operator - (const P3D & A, const P3D & B) {
    return V3D(A.x - B.x, A.y - B.y, A.z - B.z);
}
 
V3D operator * (const V3D & A, db p) {
    return V3D(A.x * p, A.y * p, A.z * p);
}
 
V3D operator / (const V3D & A, db p) {
    return V3D(A.x / p, A.y / p, A.z / p);
}
 
db pow2(db a){ 
    return a*a;
}

db dis(const P3D&A,const P3D&B){ 
    return sqrt(pow2(A.x-B.x)+pow2(A.y-B.y)+pow2(A.z-B.z));
}

db Dot(const V3D & A, const V3D & B) {
    return A.x * B.x + A.y * B.y + A.z * B.z;
}
 
db Length(const V3D & A) {
    return sqrt(Dot(A, A));
}
 
db Angle(const V3D & A, const V3D & B) {
    return acos(Dot(A, B) / Length(A) / Length(B));
}
 
V3D Cross(const V3D & A, const V3D & B) {
    return V3D(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x);
}
 
db Area2(const P3D & A, const P3D & B, const P3D & C) {
    return Length(Cross(B - A, C - A));
}
 
db Volume6(const P3D & A, const P3D & B, const P3D & C, const P3D & D) {
    return Dot(D - A, Cross(B - A, C - A));
}
 
// 四面体的重心
P3D Centroid(const P3D & A, const P3D & B, const P3D & C, const P3D & D) {
    return (A + B + C + D) / 4.0;
}
 
/************点线面*************/
// 点p到平面p0-n的距离。n必须为单位向量
db DistanceToPlane(const P3D & p, const P3D & p0, const V3D & n){
    return fabs(Dot(p - p0, n)); // 如果不取绝对值，得到的是有向距离
}
 
// 点p在平面p0-n上的投影。n必须为单位向量
P3D GetPlaneProjection(const P3D & p, const P3D & p0, const V3D & n){
    return p - n * Dot(p - p0, n);
}
 
//直线p1-p2 与平面p0-n的交点
P3D LinePlaneIntersection(P3D p1, P3D p2, P3D p0, V3D n){
    V3D v= p2 - p1;
    db t = (Dot(n, p0 - p1) / Dot(n, p2 - p1)); //分母为0，直线与平面平行或在平面上
    return p1 + v * t; //如果是线段 判断t是否在0~1之间
}
 
// 点P到直线AB的距离
db DistanceToLine(const P3D & P, const P3D & A, const P3D & B){
    V3D v1 = B - A, v2 = P - A;
    return Length(Cross(v1, v2)) / Length(v1);
}
 
//点到线段的距离
db DistanceToSeg(P3D p, P3D a, P3D b){
    if(a == b){
        return Length(p - a);
    }
    V3D v1 = b - a, v2 = p - a, v3 = p - b;
    if(Dot(v1, v2) + EPS < 0){
        return Length(v2);
    }
    else{
        if(Dot(v1, v3) - EPS > 0){
            return Length(v3);
        }
        else{
            return Length(Cross(v1, v2)) / Length(v1);
        }
    }
}
 
//求异面直线 p1+s*u与p2+t*v的公垂线对应的s 如果平行|重合，返回false
bool LineDistance3D(P3D p1, V3D u, P3D p2, V3D v, db & s){
    db b = Dot(u, u) * Dot(v, v) - Dot(u, v) * Dot(u, v);
    if(abs(b) <= EPS){return false;}
    db a = Dot(u, v) * Dot(v, p1 - p2) - Dot(v, v) * Dot(u, p1 - p2);
    s = a / b;
    return true;
}
 
// p1和p2是否在线段a-b的同侧
bool SameSide(const P3D & p1, const P3D & p2, const P3D & a, const P3D & b){
    return Dot(Cross(b - a, p1 - a), Cross(b - a, p2 - a)) - EPS >= 0;
}
 
// 点P在三角形P0, P1, P2中
bool PointInTri(const P3D & P, const P3D & P0, const P3D & P1, const P3D & P2){
    return SameSide(P, P0, P1, P2) && SameSide(P, P1, P0, P2) && SameSide(P, P2, P0, P1);
}
 
// 三角形P0P1P2是否和线段AB相交
bool TriSegIntersection(const P3D & P0, const P3D & P1, const P3D & P2, const P3D & A, const P3D & B, P3D & P){
    V3D n = Cross(P1 - P0, P2 - P0);
    if(abs(Dot(n, B - A)) <= EPS){
        return false;    // 线段A-B和平面P0P1P2平行或共面
    }
    else{    // 平面A和直线P1-P2有惟一交点
        db t = Dot(n, P0 - A) / Dot(n, B - A);
        if(t + EPS < 0 || t - 1 - EPS > 0){
            return false;    // 不在线段AB上
        }
        P = A + (B - A) * t; // 交点
        return PointInTri(P, P0, P1, P2);
    }
}
 
//空间两三角形是否相交
bool TriTriIntersection(P3D * T1, P3D * T2){
    P3D P;
    for(int i = 0; i < 3; i++){
        if(TriSegIntersection(T1[0], T1[1], T1[2], T2[i], T2[(i + 1) % 3], P)){return true;}
        if(TriSegIntersection(T2[0], T2[1], T2[2], T1[i], T1[(i + 1) % 3], P)){return true;}
    }
    return false;
}
 
//空间两直线上最近点对 返回最近距离 点对保存在ans1 ans2中
db SegSegDistance(P3D a1, P3D b1, P3D a2, P3D b2, P3D& ans1, P3D& ans2){
    V3D v1 = (a1 - b1), v2 = (a2 - b2);
    V3D N = Cross(v1, v2);
    V3D ab = (a1 - a2);
    db ans = Dot(N, ab) / Length(N);
    P3D p1 = a1, p2 = a2;
    V3D d1 = b1 - a1, d2 = b2 - a2;
    db t1, t2;
    t1 = Dot((Cross(p2 - p1, d2)), Cross(d1, d2));
    t2 = Dot((Cross(p2 - p1, d1)), Cross(d1, d2));
    db dd = Length((Cross(d1, d2)));
    t1 /= dd * dd;
    t2 /= dd * dd;
    ans1 = (a1 + (b1 - a1) * t1);
    ans2 = (a2 + (b2 - a2) * t2);
    return fabs(ans);
}
 
// 判断P是否在三角形A, B, C中，并且到三条边的距离都至少为mindist。保证P, A, B, C共面
bool InsideWithMinDistance(const P3D & P, const P3D & A, const P3D & B, const P3D & C, db mindist){
    if(!PointInTri(P, A, B, C))return 0;
    if(DistanceToLine(P, A, B) < mindist)return 0;
    if(DistanceToLine(P, B, C) < mindist)return 0;
    if(DistanceToLine(P, C, A) < mindist)return 0;
    return 1;
}
 
// 判断P是否在凸四边形ABCD（顺时针或逆时针）中，并且到四条边的距离都至少为mindist。保证P, A, B, C, D共面
bool InsideWithMinDistance(const P3D & P, const P3D & A, const P3D & B, const P3D & C, const P3D & D, db mindist){
    if(!PointInTri(P, A, B, C))return 0;
    if(!PointInTri(P, C, D, A))return 0;
    if(DistanceToLine(P, A, B) < mindist)return 0;
    if(DistanceToLine(P, B, C) < mindist)return 0;
    if(DistanceToLine(P, C, D) < mindist)return 0;
    if(DistanceToLine(P, D, A) < mindist)return 0;
    return 1;
}
/*************凸包相关问题*******************/
//加干扰
db rand01(){
    return rand() / (db)RAND_MAX;
}
db randeps(){
    return (rand01() - 0.5) * EPS;
}
P3D add_noise(const P3D & p){
    return P3D(p.x + randeps(), p.y + randeps(), p.z + randeps());
}
 
struct Face{
    int v[3];//顶点下标
    Face(int a, int b, int c){ v[0]=a;v[1]=b;v[2]=c;}
    V3D Normal(const vector<P3D> & P) const{//面的法线
        return Cross(P[v[1]] - P[v[0]], P[v[2]] - P[v[0]]);
    }
    // P[i]是否能看到面
    int CanSee(const vector<P3D> & P, int i) const{
        return Dot(P[i] - P[v[0]], Normal(P)) > 0;
    }
};
 
// 增量法求三维凸包
// 注意：没有考虑各种特殊情况（如四点共面）。实践中，请在调用前对输入点进行微小扰动
vector<Face> CH3D(const vector<P3D> & P){
    int n = P.size();
    vector<vector<int> > vis(n);
    for(int i = 0; i < n; i++){
        vis[i].resize(n);
    }
    vector<Face> cur;
    cur.push_back(Face(0, 1, 2)); // 由于已经进行扰动，前三个点不共线
    cur.push_back(Face(2, 1, 0));
    for(int i = 3; i < n; i++){
        vector<Face> next;
        // 计算每条边的“左面”的可见性
        for(int j = 0; j < cur.size(); j++) {
            Face & f = cur[j];
            int res = f.CanSee(P, i);
            if(!res){
                next.push_back(f);
            }
            for(int k = 0; k < 3; k++){
                vis[f.v[k]][f.v[(k + 1) % 3]] = res;
            }
        }
 
        for(int j = 0; j < cur.size(); j++)
            for(int k = 0; k < 3; k++){
                int a = cur[j].v[k], b = cur[j].v[(k + 1) % 3];
                if(vis[a][b] != vis[b][a] && vis[a][b]){  // (a,b)是分界线，左边对P[i]可见
                    next.push_back(Face(a, b, i));
                }
            }
        cur = next;
    }
    return cur;
}
 
struct ConvexPolyhedron{
    int n;
    vector<P3D> P, P2;
    vector<Face> faces;
    bool read(){
        if(scanf("%d", &n) != 1){
            return false;
        }
        P.resize(n);
        P2.resize(n);
        for(int i = 0; i < n; i++){
            P[i] = read_Point_3D();
            P2[i] = add_noise(P[i]);
        }
        faces = CH3D(P2);
        return true;
    }
    //三维凸包重心
    P3D centroid(){
        P3D C = P[0];
        db totv = 0;
        P3D tot(0, 0, 0);
        for(int i = 0; i < faces.size(); i++){
            P3D p1 = P[faces[i].v[0]], p2 = P[faces[i].v[1]], p3 = P[faces[i].v[2]];
            db v = -Volume6(p1, p2, p3, C);
            totv += v;
            tot = tot + Centroid(p1, p2, p3, C) * v;
        }
        return tot / totv;
    }
    //凸包重心到表面最近距离
    db mindist(P3D C){ 
        db ans = 1e30;
        for(int i = 0; i < faces.size(); i++){
            P3D p1 = P[faces[i].v[0]], p2 = P[faces[i].v[1]], p3 = P[faces[i].v[2]];
            ans = min(ans, fabs(-Volume6(p1, p2, p3, C) / Area2(p1, p2, p3)));
        }
        return ans;
    }
};
//两球体积交
db get_intersection(Circle x, Circle y) {
    db d = dis(x, y);
    if (d >= x.r + y.r) return 0;
    if (d + y.r <= x.r) return (4.0 / 3) * pi * y.r * y.r * y.r;
    if (d + x.r <= y.r) return (4.0 / 3) * pi * x.r * x.r * x.r;
    db res = 0;
    db co = (x.r * x.r + d * d - y.r * y.r) / (2.0 * d * x.r);
    db h = x.r * (1 - co);
    res += (1.0 / 3) * pi * (3.0 * x.r - h) * h * h;
    co = (y.r * y.r + d * d - x.r * x.r) / (2.0 * d * y.r);
    h = y.r * (1 - co);
    res += (1.0 / 3) * pi * (3.0 * y.r - h) * h * h;
    return res;
}
