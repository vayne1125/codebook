struct Pt{
    int x,y;
    Pt(){}
    Pt(int _x,int _y){
        x=_x,y=_y;
    }
    friend bool operator<(const Pt& lhs,const Pt& rhs){
        return lhs.x==rhs.x?lhs.y<rhs.y:lhs.x<rhs.x;
    }
    friend Pt operator-(const Pt& lhs,const Pt& rhs){
        return Pt(rhs.x-lhs.x,rhs.y-lhs.y);
    }
    friend int cross(const Pt& o,const Pt& a,const Pt& b){
        Pt lhs = o-a, rhs = o-b;
        return lhs.x*rhs.y - lhs.y*rhs.x;
    }
};
vector<Pt> convex_hull(vector<Pt> hull){ //回傳凸包陣列
    sort(hull.begin(),hull.end());
    int top=0;
    vector<Pt> stk;
    for(int i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<=0)
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    for(int i=hull.size()-2,t=top+1;i>=0;i--){
        while(top>=t&&cross(stk[top-2],stk[top-1],hull[i])<=0)
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    stk.pop_back();
    return stk;
}
double FarthestPair(vector<Pt> arr) { //回傳最遠點對
    double ret = 0;
    for (int i = 0, j = i + 1; i < arr.size(); i++) {
        while (distance(i, j) < distance(i, (j + 1) % arr.size())) {
            j = (j + 1) % arr.size();
        }
        ret = max(ret, distance(i, j));
    }
    return ret;
}
vector<Pt> tui;
double distance(int i, int j) {
    double a = (tui[i].x - tui[j].x) * (tui[i].x - tui[j].x),
           b = (tui[i].y - tui[j].y) * (tui[i].y - tui[j].y);
    return sqrt(a + b);
}