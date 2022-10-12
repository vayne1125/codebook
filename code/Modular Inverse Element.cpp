ll f[MXN+1] = { 0 }, inv[MXN+1] = {0};
ll mypow(ll x, ll y, ll m) {    //x^y % m
	ll ret = 1 % m;
	while (y) {
		if (y & 1)    ret = ret * x % m;
		x = x * x % m;
		y >>= 1;
	}
	return ret;
}
void init() {
	f[0] = 1;    // 0! = 1
	for (int i = 1; i <= MXN; i++) { //1!到n!
		f[i] = f[i - 1] * i % MOD;
	}
	inv[MXN] = mypow(f[MXN], (MOD - 2), MOD);
	for (long long i = MXN - 1; i >= 0; i--) { //模逆元
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
}
ll C(int n, int m) { //用途再算C幾取幾 % MOD
	return f[n] * inv[m] % MOD * inv[n - m] % MOD;
}