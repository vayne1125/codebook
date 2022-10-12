double Direction(point Pi, point Pj, point Pk){
	return (Pj.x-Pi.x)*(Pk.y-Pi.y)-(Pk.x-Pi.x)*(Pj.y-Pi.y);
}

bool isIntersect(line p, line q){
  double d1, d2, d3, d4;
  d1 = Direction(p.a, p.b, q.a);
  d2 = Direction(p.a, p.b, q.b);
  d3 = Direction(q.a, q.b, p.a);
  d4 = Direction(q.a, q.b, p.b);
  if(d1*d2<0 && d3*d4<0)  { return true;}  //規範相交
  //非規範相交
  else return false;
}