#define ld long double
struct Pt {
  ld x, y;
  Pt(ld _x=0, ld _y=0):x(_x), y(_y) {}
  
  Pt operator+(const Pt &a){
    return Pt(x+a.x, y+a.y);
  }
  Pt operator-(const Pt &a){
    return Pt(x-a.x, y-a.y);
  }
  Pt operator*(const ld &a){
    return Pt(x*a, y*a);
  }
  Pt operator/(const ld &a){
    return Pt(x/a, y/a);
  }
  ld operator*(const Pt &a){ //程式碼中內積通常用*表示
    return x*a.x + y*a.y;
  }
  ld operator^(const Pt &a){ //程式碼中外積通常用^表示
    return x*a.y - y*a.x;
  }
  bool operator<(const Pt &a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
};
//判斷3點共線
bool collinearity(const Pt& a, const Pt& b, const Pt& c){
    return (b-a)^(c-a) < EPS;
}
//判斷點是否再線段上
bool inLine(const Pt& p, const Line& li){
    return collinearity(li.st, li.ed, p) && (li.st-p)*(li.ed-p) < EPS;
}