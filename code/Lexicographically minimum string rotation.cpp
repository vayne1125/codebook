#define rep(b,a,N) for(int b=a;b<N;b++)
int minRotation(string s) { //Lexicographically minimum string rotation
	//rotate後使字典序最小
	int a = 0, N = s.size(); s += s;
	rep(b, 0, N) rep(k, 0, N) {
		if (a + k == b || s[a + k] < s[b + k])
		{
			b += max(0, k - 1); break;
		}
		if (s[a + k] > s[b + k]) { a = b; break; }
	} return a;
}