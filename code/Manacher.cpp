void z_value_pal(string s, int len, int *z) { //z陣列儲存以每個字元為中心的回文半徑+1 s的size要是原字串*2+1
	len = (len << 1) + 1;
	for (int i = len - 1; i >= 0; i--)
		s[i] = i & 1 ? s[i >> 1] : '@';
	z[0] = 1;
	for (int i = 1, l = 0, r = 0; i < len; i++) {
		z[i] = i < r ? min(z[l + l - i], r - i) : 1;
		while (i - z[i] >= 0 && i + z[i] < len&&s[i - z[i]] == s[i + z[i]])++z[i];
		if (i + z[i] > r) l = i, r = i + z[i];
	}
}
//s =“@a@b@a@a@c@”
//z = [12141232121]
//原字串為a,要傳a+a+'0'進去,不然會re.

