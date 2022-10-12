LL x[N],m[N];
LL CRT(LL x1, LL m1, LL x2, LL m2) {
  LL g = __gcd(m1, m2);
  if((x2 - x1) % g) return -1;// no sol
  m1 /= g; m2 /= g;
  pair<LL,LL> p = gcd(m1, m2);
  LL lcm = m1 * m2 * g;
  LL res = p.first * (x2 - x1) * m1 + x1;
  return (res % lcm + lcm) % lcm;
}
LL solve(int n){ // n>=2,be careful with no solution
	LL res=CRT(x[0],m[0],x[1],m[1]),p=m[0]/__gcd(m[0],m[1])*m[1];
	for(int i=2;i<n;i++){
		res=CRT(res,p,x[i],m[i]);
		p=p/__gcd(p,m[i])*m[i];
	}
	return res;
}

/*   x ≡ 2 (mod 5)
     x ≡ 3 (mod 7)
     x ≡ 4 (mod 11)

     x[3] = {2,3,5};
     m[3] = {5,7,11};
     n = 3 
*/