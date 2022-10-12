// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n−2] if
// you want to use magic.
//<ex> magic[3] ={2,7,61};
#define ull unsigned long long
ull magic[]={}
ull mul(ull a, ull b, ull c) {  //快速乘
	ull ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % c;
		a = (a + a) % c;
		b >>= 1;
	}
	return ans;
}
ull mypow(ull a, ull u, ull n) {
	ull ans = 1;
	while (u) {
		if (u & 1) ans = mul(ans,a,n);
		a = mul(a,a,n);  
		u >>= 1;  
	}
	return ans;
}
bool witness(ull a, ull n, ull u, ull t) {
	if (!a) return 0;
	ull x = mypow(a, u, n); //a^u % n
	for (int i = 0; i < t; i++) {
		ull nx = mul(x, x, n);
		if (nx == 1 && x != 1 && x != n-1) return 1;
		x = nx;
	}
	return x != 1;
}
bool miller_rabin(ull n) {
	int s = (magic numbers size);
		// iterate s times of witness on n
		if(n < 2) return 0;
	if (!(n & 1)) return n == 2;
	ull u = n-1; ull t = 0;
	// n‐1 = u*2^t
	while (!(u & 1)) u >>= 1, t++;
	while (s--) {
		ull a = magic[s] % n;
		if (witness(a, n, u, t)) return 0;
	}
	return 1;
}